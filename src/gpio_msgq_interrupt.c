#include <zephyr.h>
#include <zephyr.h>
#include <device.h>
#include <kernel.h>
#include <devicetree.h>
#include <drivers/gpio.h>

#define DEV_IN DT_NODELABEL(gpioa)
#define DEV_OUT DT_NODELABEL(gpioa)
#define PIN_OUT 0
#define PIN_IN 1
#define STACKSIZE 500

struct gpio_callback callback2;

struct data_item_type {
    uint32_t field1;
    uint32_t field2;
    
};


char my_msgq_buffer[10*sizeof(struct data_item_type)];

struct k_msgq my_msgq;

struct k_thread toggle_thread;

K_THREAD_STACK_DEFINE(coop_stack, STACKSIZE);


void pin_interrupt2(const struct device *port,
                   struct gpio_callback *cb,
                   gpio_port_pins_t pins_)
{
    struct data_item_type sig_received = {1,2};
    //add message to message queue   
    while(k_msgq_put(&my_msgq,&sig_received, K_NO_WAIT) != 0 ){
        //purge msgq if full
        k_msgq_purge(&my_msgq);
    }
    
}

//thread that reads message queue
void toggle_pin_after_message(const struct device *port){
    struct data_item_type received_data;
    //get message off of queue
    while(1){
        k_msgq_get(&my_msgq, &received_data, K_FOREVER);
        //toggles output pin when message received:
        if(received_data.field1 == 1){
            k_sleep(K_MSEC(.8))
            gpio_pin_toggle(port, PIN_OUT);
        }
    }
}


void msgq_interrupt_main(void)
{
	const struct device *dev_in, *dev_out;
    dev_in = device_get_binding(DT_LABEL(DEV_IN));
    dev_out = device_get_binding(DT_LABEL(DEV_OUT));
    k_msgq_init( &my_msgq, my_msgq_buffer, sizeof(struct data_item_type),10);
    k_thread_create(&toggle_thread,
                    coop_stack, 
                    STACKSIZE,
                    (k_thread_entry_t)toggle_pin_after_message,
                    (void*)dev_out, NULL, NULL,
                    K_PRIO_COOP(1),
                    0,
                    K_NO_WAIT
                    );

    gpio_pin_configure(dev_out, PIN_OUT, GPIO_OUTPUT_ACTIVE);
    gpio_pin_configure(dev_in, PIN_IN, GPIO_INPUT);
    gpio_pin_interrupt_configure(dev_in, PIN_IN, GPIO_INT_EDGE_RISING);
    gpio_init_callback(&callback2, pin_interrupt2, 1 << PIN_IN);
    gpio_add_callback(dev_in, &callback2);
    k_sleep(K_FOREVER);
    
}

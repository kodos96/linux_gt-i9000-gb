#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Bowen <kevin.t.bowen@gmail.com>");
MODULE_DESCRIPTION("Talon");

static int foo;

static void test(void) {
        int *test;
        printk("kodos: allocating 1mb\n");
        test = kmalloc(1024*1024, GFP_KERNEL);
        if (!test)
                printk("kodos: allocation failed\n");
        else {
              	printk("kodos: allocation succeeded\n");
                kfree(test);
        }
	printk("kodos: allocating 2mb\n");
        test = kmalloc(1024*1024*2, GFP_KERNEL);
        if (!test)
               	printk("kodos: allocation failed\n");
        else {
               	printk("kodos: allocation succeeded\n");
                kfree(test);
        }
	printk("kodos: allocating 4mb\n");
        test = kmalloc(1024*1024*4, GFP_KERNEL);
        if (!test)
                printk("kodos: allocation failed\n");
        else {
              	printk("kodos: allocation succeeded\n");
                kfree(test);
        }
	printk("kodos: allocating 8mb\n");
        test = kmalloc(1024*1024*8, GFP_KERNEL);
        if (!test)
                printk("kodos: allocation failed\n");
        else {
              	printk("kodos: allocation succeeded\n");
                kfree(test);
        }
	printk("kodos: allocating 16mb\n");
        test = kmalloc(1024*1024*16, GFP_KERNEL);
        if (!test)
                printk("kodos: allocation failed\n");
        else {
              	printk("kodos: allocation succeeded\n");
                kfree(test);
        }
	printk("kodos: allocating 32mb\n");
        test = kmalloc(1024*1024*32, GFP_KERNEL);
        if (!test)
                printk("kodos: allocation failed\n");
        else {
              	printk("kodos: allocation succeeded\n");
                kfree(test);
        }

}

static ssize_t foo_show(struct kobject * kobj, struct kobj_attribute * attr, char * buf)
{
 return sprintf(buf, "%d\n", foo);
}

static ssize_t foo_store(struct kobject * kobj, struct kobj_attribute * attr, const char * buf, size_t count)
{
 sscanf(buf, "%du", &foo);
 test();
 return count;
}

static struct kobj_attribute foo_attribute = __ATTR(foo, 0666, foo_show, foo_store);

static struct attribute * attrs [] =
{
 &foo_attribute.attr,
 NULL,
};

static struct attribute_group attr_group = {
 .attrs = attrs,
};

static struct kobject *ex_kobj;

static int __init talon_init(void) {
	int retval;

	printk("talon init\n");

	ex_kobj = kobject_create_and_add("ex", kernel_kobj);
	if(!ex_kobj)
		return ENOMEM;

	retval = sysfs_create_group(ex_kobj, &attr_group);

	if(retval)
		kobject_put(ex_kobj);
	
	return retval;
}

static void __exit talon_exit(void) {
	printk("talon exit\n");
}

module_init(talon_init);
module_exit(talon_exit);


#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <linux/device.h>
#include <linux/configfs.h>
#include <linux/unistd.h>
#include <../drivers/nvme/host/nvme.h>
#include <../drivers/nvme/target/nvmet.h>

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Jake Choi");
MODULE_DESCRIPTION("A Simple NVMe Write Test Module");
MODULE_INFO(vermagic, "4.9.16+ SMP mod_unload ");
MODULE_INFO(intree, "Y");

//extern void nvme_start_queues(struct nvme_ctrl *ctrl); 
//extern int nvmet_ns_enable(struct nvmet_ns *ns)
//extern int nvmet_register_transport(struct nvmet_fabrics_ops *ops);
//extern void nvmet_ctrl_put(struct nvmet_ctrl *ctrl);
extern ssize_t nvmet_addr_adrfam_show(struct config_item *item, char *page);
extern ssize_t nvmet_addr_adrfam_store(struct config_item *item, char *page, size_t count);
extern struct config_group *nvmet_subsys_make(struct config_group *, const char *);
//extern static struct configfs_group_operations nvmet_subsystems_group_ops;
//extern ssize_t nvmet_subsys_attr_allow_any_host_store(struct config_item *, const char *, size_t);
//extern ssize_t nvmet_subsys_attr_allow_any_host_show(struct config_item *, char *);
extern struct config_group nvmet_subsystems_group; 

extern long sys_mkdir(const char __user *pathname, int mode);

static int __init write_init(void)
{

//struct nvmet_ctrl *ctrl;
	char shit[30];
//	struct config_item theItem;
//	struct config_group *my_group;
	//struct file *fp = (struct file *) NULL;
	//fp = filp_open("/home/dcslab/foofie", O_DIRECTORY|O_CREAT, S_IRUSR);	
	sys_mkdir("/home/dcslab/foofie", 0700);
//	nvmet_register_transport(&lol);
//	nvmet_ctrl_put(ctrl);		
//	nvmet_init();		
//
	
//	my_group = nvmet_subsys_make(NULL, "Coolio");
//	nvmet_subsys_attr_allow_any_host_store(&my_group->cg_item, "1", 1);
//	nvmet_subsys_attr_allow_any_host_show(&my_group->cg_item, shit);


	printk(KERN_INFO "Loading Write Module! %s", shit);

	

	return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit write_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
}

module_init(write_init);
module_exit(write_cleanup);

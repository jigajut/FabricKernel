#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

struct stat st = {0};

int main() {

	int filedesc;

	if (stat("/sys/kernel/config/nvmet/subsystems/jakesystem", &st) == -1) {
	    mkdir("/sys/kernel/config/nvmet/subsystems/jakesystem", 0700); 
	}
	
	filedesc = open("/sys/kernel/config/nvmet/subsystems/jakesystem/attr_allow_any_host", O_WRONLY);
	
	if (filedesc < 0) 
	{
		write(2,"error opening subsystem\n",20);
		return -1;
	}

	if (write(filedesc, "1", 1) != 1) {
        	write(2, "There was an error writing to attr_allow_any_host\n", 50);
	       return -1;
	}
	
	close(filedesc);
	
	if (stat("/sys/kernel/config/nvmet/subsystems/jakesystem/namespaces/10", &st) == -1) {
	    mkdir("/sys/kernel/config/nvmet/subsystems/jakesystem/namespaces/10", 0700); 
	}

	filedesc = open("/sys/kernel/config/nvmet/subsystems/jakesystem/namespaces/10/device_path", O_WRONLY);
	if (filedesc < 0) 
	{
		write(2,"error opening device_path\n",20);
		return -1;
	}
	if (write(filedesc, "/dev/nvme0n1", 12) != 12) {
        	write(2, "There was an error writing to device_path\n", 50);
	       return -1;
	}
	close(filedesc);

	filedesc = open("/sys/kernel/config/nvmet/subsystems/jakesystem/namespaces/10/enable", O_WRONLY);
	if (filedesc < 0) 
	{
		write(2,"error opening enable\n",20);
		return -1;
	}
	if (write(filedesc, "1", 1) != 1) {
        	write(2, "There was an error writing to enable\n", 50);
	       return -1;
	}
	close(filedesc);

	if (stat("/sys/kernel/config/nvmet/ports/1", &st) == -1) {
		mkdir("/sys/kernel/config/nvmet/ports/1", 0700); 
	}

	filedesc = open("/sys/kernel/config/nvmet/ports/1/addr_traddr", O_WRONLY);
	if (filedesc < 0) 
	{
		write(2,"error opening addr_traddr\n",20);
		return -1;
	}
	if (write(filedesc, "10.0.0.10\n", 10) != 10) {
        	write(2, "There was an error writing to addr_traddr\n", 50);
	       return -1;
	}
	close(filedesc);

	filedesc = open("/sys/kernel/config/nvmet/ports/1/addr_trtype", O_WRONLY);
	if (filedesc < 0) 
	{
		write(2,"error opening addr_trtype\n",20);
		return -1;
	}
	if (write(filedesc, "rdma", 4) != 4) {
        	write(2, "There was an error writing to addr_trtype\n", 50);
	       return -1;
	}
	close(filedesc);

	filedesc = open("/sys/kernel/config/nvmet/ports/1/addr_trsvcid", O_WRONLY);
	if (filedesc < 0) 
	{
		write(2,"error opening addr_trsvcid\n",20);
		return -1;
	}
	if (write(filedesc, "4420\n", 5) != 5) {
        	write(2, "There was an error writing to addr_trsvcid\n", 50);
	       return -1;
	}
	close(filedesc);

	filedesc = open("/sys/kernel/config/nvmet/ports/1/addr_adrfam", O_WRONLY);
	if (filedesc < 0) 
	{
		write(2,"error opening addr_adrfam\n",20);
		return -1;
	}
	if (write(filedesc, "ipv4", 4) != 4) {
        	write(2, "There was an error writing to addr_adrfam\n", 50);
	       return -1;
	}
	close(filedesc);
	
	symlink("/sys/kernel/config/nvmet/subsystems/jakesystem", "/sys/kernel/config/nvmet/ports/1/subsystems/jakesystem");

	return 0;
}	

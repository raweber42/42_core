# CHEATSHEET

## SIMPLE SETUP
### How does a virtual machine work?
- Simulates virtual hardware through *virtualization*
- runs applications and other operating systems independent from host machine
- physical machine: *host*, virtual machine(s): *guest*<br/>

### Basic differences between CentOS and Debian
|CentOS|Debian|
|------|------|
|rebuild from Red Hat commercial distribution|build by independent developers|
|more user-friendly|not so user-friendly|
|very stable, less updates|stable, more updates|
|few packages|huge amount of packages|
<br/>

### Purpose of Virtual Machines
<br/>
### DEBIAN: Difference between 'aptitude' and 'apt'
|apt|aptitude|
|------|------|
|low-level package manager|high-level package manager|
|no graphical interface|interactive user interface|
||includes apt functionalities|
||search function for packages|
<br/>
### DEBIAN: What is AppArmour?
- type of *mandatory access control* (MAC)
- restricts programs to certain resources
- "prevents applications from turning evil"
<br/>

### Check that UFW is running
- run `sudo ufw status`
<br/>

### Check that SSH is running
- run `systemctl status ssh`
<br/>

### Check Distrubution/Operating System
- run `uname -a`
<br/>

## USER
### Check that user belongs to groups 'sudo' and 'user42'
- run `groups`
<br/>

### Create a new user (warning: password policy has to be working!)
- run `sudo adduser <new_user>`
- for verifying: `cat /etc/passwd`
<br/>

### Explain how to setup password policy
- for password quality: `/etc/security/pwquality.conf`
- for password expiration: `/etc/login.defs`
<br/>

### Create a new group 'evaluating'
- run `sudo groupadd evaluating`
- for verifying: `cat /etc/group`
<br/>

### Assign user to group 'evaluating'
- run `sudo usermod -aG evaluating <username>`
<br/>

### Check if user belongs to group 'evaluating'
- run `groups`
<br/>

### Advantages and disadvantages of the password policy
- Advantages: forces stronger passwords, no '*123456*'
- Disadvantages: hard to remember, easy to guess for computers ([see here](https://i0.wp.com/www.sapien.com/blog/wp-content/uploads/2020/10/password-strength.png?w=740&ssl=1))
<br/>

## HOSTNAME AND PARTITIONS
### Check hostname (must be login42)
- run `hostname`
<br/>

### Modify the hostname (check with reboot)
1. change hostname in `/etc/hostname` to your wished hostname
2. add the following line after the existing hosts in `/etc/hosts`:
	* `127.0.1.1	<newhostname>`
3. reboot with `sudo reboot`
<br/>

### Restore old hostname
1. change hostname in `/etc/hostname` to your old hostname (`<yourlogin>42`)
2. remove the line you added in `/etc/hosts` (`127.0.1.1	<newhostname>`)
3. reboot with `sudo reboot`
<br/>

### Show the partitions of the VM
- run `lsblk`
<br/>

### How do LVMs work? What are they useful for?
- Logical Volume Management, is a storage device management technology that gives users the power to pool and abstract the physical layout of component storage devices for easier and flexible administration.
- Volumes can be resized *dynamically* as space requirements change and can be *migrated* between physical devices.
- So you can easily change partitions, add and remove hardware devices for storage and so on ...
<br/>

## SUDO
### Check that 'sudo' is installed
- run `which sudo` or `sudo --version`
<br/>

### Assign new user to group 'sudo'
- run `sudo usermod -aG sudo <new_user>`
<br/>

### Explain value and operation of sudo
- sudo stands for *superuser do*
- temporarily gives selected users the ability to run commands at *root level* without having to login as root
<br/>

### Show the sudo rule implementations
- run `sudo visudo`
<br/>

### Check that '/var/log/sudo/' exists and has at least one file
> You should see a history of the commands used with sudo
> run one command with sudo and check that it was registered
<br/>

## UFW
### Check that UFW is properly installed
- run `sudo ufw --version`
<br/>

### Check that UFW is working
- run `sudo systemctl status ufw`
<br/>

### What is UFW? What is the value of using it?
- UFW is short for *uncomplicated firewall*
- easy-to-use firewall for managing (network-) ports
<br/>

### List active rules in UFW
- run `sudo ufw status`
	* rule for port 4242 must exist (additional ports allowed for bonus)
<br/>

### Add rule to open port 8080 
- run `sudo ufw allow 8080`
<br/>

### Check that 8080 has been added
- run `sudo ufw status` again
<br/>

### Delete the new rule
1. run `sudo ufw status`
2. check the number of the **row** you want to delete
3. run `sudo ufw delete <numberofrow>` for each of the **two** open ports *8080 and 8080 (V6)*
<br/>

## SSH
### Check that SSH is properly installed
- run `shh -V`
<br/>

### Check that SSH is working
- run `sudo systemctl status ssh`
<br/>

### What is SSH?
- short for **S**ecure **SH**ell'
- protocol for securely logging into remote machines across a network, with encryption to protect the transferred information and authentication to ensure access only for authorized users

### Check that SSH only uses port 4242
- open the config file with `sudo nano /etc/ssh/sshd_config` and scroll to `Port 4242`
<br/>

### Check that SSH works for newly created user
- open a terminal at your local machine
- run `ssh <new_user>@<your_ip_address> -p 4242`
- login with the credentials of the newly created user
<br/>

### Check that SSH is *disabled* for root login
- open the config file with `sudo nano /etc/ssh/sshd_config` and scroll to `PermitRootLogin`
<br/>

## SCRIPT MONITORING
### How does the script work?
- bash script that saves the output of different commands in variables and displays them in the format given in the subject paper when run with `bash` command
- runs every ten minutes thanks to `cron` command
<br/>

### What is 'cron'?
- system utility to schedule programs to run automatically at predetermined intervals/dates/times
<br/>

### Modify the script to run *every minute*
- run `sudo crontab -e`
- modify the line 
	* `*/10 * * * * bash /<path_to_your_monitoring_script>`
	to be
	`*/1 * * * * bash /<path_to_your_monitoring_script>`
<br/>

### Stop the script running from startup *without* modifying the script itself
- run `sudo systemctl disable cron`
- restart with `sudo reboot`
- check `sudo systemctl status cron` to verify it's not running
<br/>

## BONUS
### Check bonus partitions
- run `lsblk`
<br/>

### Check that wordpress is running
- get you IP-Adress with `ip a | grep inet`
- paste the IP adress in your browser and show your website
- to show that you actually can modify the website with wordpress paste `http://<your_ip_address>/wp-login.php` into your browser
<br/>

### Explain and show additional service (*HERE: ftp-server*)
- run `touch testfile` to create a testfile that you will put on your ftp server
- run `ftp <your_ip_address>` and login with your credentials
- run `put testfile` and after that `ls` to show that you can upload files
- run `get testfile testfile_download`, `exit` and then `ls` to show that you can download the testfile again (renamed so you can actually *see* that you downloaded it)
<br/>

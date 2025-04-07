## JetBackup 5 Panel Integration

### install `jetbackup5-base` package from ALPHA tier


```shell
bash <(curl -LSs http://repo.jetlicense.com/static/install)
```

#### - RedHet OS's

```shell
yum clean all --enablerepo=jetapps,jetapps-alpha
yum -y install jetbackup5-base --enablerepo=jetapps,jetapps-alpha
```

#### - Debian/Ubuntu OS's

```shell
mv /etc/apt/sources.list.d/jetapps-alpha.list.disabled /etc/apt/sources.list.d/jetapps-alpha.list
apt-get update
apt-get install -y jetbackup5-base
mv /etc/apt/sources.list.d/jetapps-alpha.list /etc/apt/sources.list.d/jetapps-alpha.list.disabled
```

Panel integration should be implemented under `/usr/local/jetapps/var/lib/jetbackup5/Panel` directory

On jetbackup5 plugin entry point (within your panel) you will need to execute `/usr/local/jetapps/usr/bin/jetbackup5/jetbackup_admin` as the account, This will output the plugin UI (HTML content).

Example:
```shell
#!/bin/bash
echo -en "HTTP/1.1 200 OK\r\n";
/usr/local/jetapps/usr/bin/jetbackup5/jetbackup_admin
```

This will execute your implementation of `/usr/local/jetapps/usr/bin/jetbackup5/jetbackup_admin_exec` as root (This file must be set to root:root ownership and 0700 permissions)

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

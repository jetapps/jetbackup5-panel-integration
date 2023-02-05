## JetBackup 5 Panel Integration

### install `jetbackup5-base` package from ALPHA tier

#### - RedHet OS's

```
# yum -y install https://repo.jetlicense.com/centOS/jetapps-repo-latest.rpm --disablerepo=*
# yum -y install jetbackup5-base --disablerepo=* --enablerepo=jetapps-alpha
```

#### - Debian/Ubuntu OS's

```
# apt-get install -y gnupg
# curl -sS http://repo.jetlicense.com/static/jetapps.asc | gpg --dearmor | tee /etc/apt/trusted.gpg.d/jetapps.gpg >/dev/null
# dpkg --install <(wget --quiet --output-document=- https://repo.jetlicense.com/$( cat /etc/os-release | grep -E '^ID=' | cut -c4- )/jetapps-repo-latest_amd64.deb)
# mv /etc/apt/sources.list.d/jetapps-alpha.list.disabled /etc/apt/sources.list.d/jetapps-alpha.list
# apt-get update
# apt-get install -y jetbackup5-base
# mv /etc/apt/sources.list.d/jetapps-alpha.list /etc/apt/sources.list.d/jetapps-alpha.list.disabled
```

Panel integration should be implemented under `/usr/local/jetapps/var/lib/jetbackup5/Panel` directory

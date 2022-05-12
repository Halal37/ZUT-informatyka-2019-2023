#! /bin/bash
# SO IS1 223A LAB07
# Wojciech Lidwin
# lw46577@zut.edu.pl
lista=$(ls /proc | grep [[:digit:]] | sort -n)
case "$1" in 
 "-p")
 for dir in $lista;
 do
  if [ -e /proc/"$dir" ]
  then
   Pid=$(grep '^Pid:' /proc/$dir/status | awk '{print $2}') 
   Name=$(grep '^Name:' /proc/$dir/status | awk '{print $2}') 
   PPid=$(grep '^PPid:' /proc/$dir/status | awk '{print $2}') 
   pom_Uid=$(grep '^Uid:' /proc/$dir/status | awk '{print $2}') 
   Uid_name=$(id -nu $pom_Uid)
   echo "$Pid $PPid $pom_Uid($Uid_name) $Name" 
  fi
 done
 ;;
 "-u")
 for dir in $lista;
 do
  if [ -e /proc/"$dir" ]
  then
   Pid=$(grep '^Pid:' /proc/$dir/status | awk '{print $2}') 
   Name=$(grep '^Name:' /proc/$dir/status | awk '{print $2}') 
   pom_Uid=$(grep '^Uid:' /proc/$dir/status | awk '{print $2}') 
   Uid_name=$(id -nu $pom_Uid)
   katalog_roboczy=$(readlink /proc/$dir/cwd)
   if [ $Uid_name != "root" ] 
   then
    echo "$Pid $Name $katalog_roboczy" 
   fi
  fi
 done
 ;;
 *) echo "Musisz podac opcje lub podales inna niz -p lub -u"
esac


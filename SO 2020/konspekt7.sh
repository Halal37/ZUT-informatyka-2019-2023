#! /bin/bash
#/proc
lista=$(ls /proc/[0-9]* | grep [[:digit:]] | sed 's/.$//' | sort -V)
case "$1" in 
 "-p")
 for dir in $lista;
 do
  if [ -e "$dir" ]
  then
   Pid=$(grep '^Pid:' $dir/status | awk '{print $2}') 
   Name=$(grep '^Name:' $dir/status | awk '{print $2}') 
   PPid=$(grep '^PPid:' $dir/status | awk '{print $2}') 
   pom_Uid=$(grep '^Uid:' $dir/status | awk '{print $2}') 
   Uid_name=$(id -nu $pom_Uid)
   echo "$Pid $PPid $pom_Uid($Uid_name) $Name" 
  fi
 done
 ;;
 "-u")
 for dir in $lista;
 do
  if [ -e "$dir" ]
  then
   Pid=$(grep '^Pid:' $dir/status | awk '{print $2}') 
   pom_Uid=$(grep '^Uid:' $dir/status | awk '{print $2}') 
   Uid_name=$(id -nu $pom_Uid)
   katalog_roboczy=$(readlink $dir/cwd)
   echo "$Pid $Uid_name $katalog_roboczy" 
  fi
 done
 ;;
 *) echo "Musisz podac opcje lub podales inna niz -p lub -u"
esac


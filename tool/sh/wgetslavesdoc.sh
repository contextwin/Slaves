#!/bin/sh
# 外部コマンド wgetコマンドに依存しています!!
DATE=`date "+%Y%m%d_%H%M%S"`
THISPROJECTS="/home/contextwin/work/src/Slaves/Slaves/doc/thisproject/"

wget http://contextwin.livedoor.blog
cat index.html | grep sidebody | grep -v 2020 | awk '{print substr($0, index($0, "archives/"))}' | awk '{sub(".html.*", "");print $0;}' | awk '{sub("archives/", "");print $0;}' > page_list.txt

rm index.html

for LIST in `cat page_list.txt`
do
 if [ ! -e ${THISPROJECTS}${LIST} ]; then
 mkdir ${THISPROJECTS}${LIST}
 mkdir ${THISPROJECTS}${LIST}/current
 touch ${THISPROJECTS}${LIST}/current/a.html
 mkdir ${THISPROJECTS}${LIST}/old
 fi
done

for LIST in `cat page_list.txt`
do
 wget -O "${THISPROJECTS}${LIST}/${DATE}.html" http://contextwin.livedoor.blog/archives/${LIST}.html
done

for LIST in `cat page_list.txt`
do
WC=`diff ${THISPROJECTS}${LIST}/${DATE}.html ${THISPROJECTS}${LIST}/current/*.html | wc -l`
if [ ${WC} -gt 0 ]; then
  echo updated ${LIST} 
  mv ${THISPROJECTS}${LIST}/current/*.html ${THISPROJECTS}${LIST}/old/.
  mv ${THISPROJECTS}${LIST}/${DATE}.html ${THISPROJECTS}${LIST}/current/.
  if [ -e ${THISPROJECTS}${LIST}/old/a.html ]; then
   rm ${THISPROJECTS}${LIST}/old/a.html
  fi
 else
  echo no-updated ${LIST}	 
  rm ${THISPROJECTS}${LIST}/${DATE}.html
fi
done

rm page_list.txt

#below easy explanation web pages url of this tool.
#http://contextwin.livedoor.blog/archives/5808849.html

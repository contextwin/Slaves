#!/bin/sh
DATE=`date "+%Y%m%d_%H%M%S"`
THISPROJECTS="/home/contextwin/work/src/Slaves/Slaves/doc/thisproject/"
for LIST in "5307375" "5331764" "5402599" "5422771" "5435893"
do
wget -O "${THISPROJECTS}${LIST}/${DATE}.html" http://contextwin.livedoor.blog/archives/${LIST}.html
#wget -O "${THISPROJECTS}5307375/${DATE}.html" http://contextwin.livedoor.blog/archives/5307375.html
#wget -O "${THISPROJECTS}5331764/${DATE}.html" http://contextwin.livedoor.blog/archives/5331764.html
#wget -O "${THISPROJECTS}5402599/${DATE}.html" http://contextwin.livedoor.blog/archives/5402599.html
#wget -O "${THISPROJECTS}5422771/${DATE}.html" http://contextwin.livedoor.blog/archives/5422771.html
#wget -O "${THISPROJECTS}5435893/${DATE}.html" http://contextwin.livedoor.blog/archives/5435893.html
done

for LIST in "5307375" "5331764" "5402599" "5422771" "5435893"
do
WC=`diff ${THISPROJECTS}${LIST}/${DATE}.html ${THISPROJECTS}${LIST}/curent/*.html | wc -l`
if [ ${WC} -gt 0 ]; then
  echo updated ${LIST} 
  mv ${THISPROJECTS}${LIST}/curent/*.html ${THISPROJECTS}${LIST}/old/.
  mv ${THISPROJECTS}${LIST}/${DATE}.html ${THISPROJECTS}${LIST}/curent/.
 else
  echo no-updated ${LIST}	 
  rm ${THISPROJECTS}${LIST}/${DATE}.html
fi
done

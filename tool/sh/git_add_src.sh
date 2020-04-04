#!/bin/sh
DATE=`date`
/usr/bin/git add main.c function.h view.h mysdl2.h specific.h tool image fonts doc music README Makefile Slaves-0.1
/usr/bin/git commit -m "${DATE}"
/usr/bin/git push origin master

#below easy explanation web pages url of this tool.
#http://contextwin.livedoor.blog/archives/5808849.html

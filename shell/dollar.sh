#!/bin/bash

my_file=/dir4/dir5/my2.file2.text2

echo '${file-my_file}' =  ${file-my_file}
echo '${file:-my_file}' =  ${file:-my_file}
echo '${file+my_file}' =  ${file+my_file}
echo '${file:+my_file}' =  ${file:+my_file}
echo '$file' = $file
echo ""

file=
echo '${file-my_file}' =  ${file-my_file}
echo '${file:-my_file}' =  ${file:-my_file}
echo '${file+my_file}' =  ${file+my_file}
echo '${file:+my_file}' =  ${file:+my_file}
echo '$file' = $file
echo ""

file=/dir1/dir2/dir3/my.file.txt
echo '$file' = $file
echo '${file-my_file}' =  ${file-my_file}
echo '${file:-my_file}' =  ${file:-my_file}
echo '${file+my_file}' =  ${file+my_file}
echo '${file:+my_file}' =  ${file:+my_file}
echo '$file' = $file
echo ""
echo "==========================================="
echo ""

echo '${file2=my.file.txt}' = ${file2=my.file.txt}
echo '${file2:=my.file.txt}' = ${file2:=my.file.txt}
echo '$file2' = $file2
echo ""

file2=
echo '${file2=my.file.txt}' = ${file2=my.file.txt}
echo '${file2:=my.file.txt}' = ${file2:=my.file.txt}
echo '${file2?my.file.txt}' = ${file2?my.file.txt}
echo '${file2:?my.file.txt}' = ${file2:?my.file.txt}
echo '$file2' = $file2
echo ""

file2=/dirA/dirB/myA.fileA.txt
echo '${file2=my.file.txt}' = ${file2=my.file.txt}
echo '${file2:=my.file.txt}' = ${file2:=my.file.txt}
echo '${file2?my.file.txt}' = ${file2?my.file.txt}
echo '${file2:?my.file.txt}' = ${file2:?my.file.txt}
echo '$file2' = $file2
echo ""

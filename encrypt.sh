#!/bin/bash

read -p "What is your message? " message
touch inputFile.txt
cat << EOF > inputFile.txt
e
yo
secret
e
$message
n
EOF

currentDate=`date "+%B %d %Y, %R"`
echo $currentDate >> encryptedMessages.txt

cat inputFile.txt | ./a.exe | head -n 7 | tail -n 1 >> encryptedMessages.txt
rm inputFile.txt

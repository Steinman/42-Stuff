ldapsearch -Q -b "dc=42, dc=fr" 'uid=z*' | grep "cn: " | cut -c5- | sort -r

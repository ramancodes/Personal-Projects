import re

myStr = 'My Phone No. : +916204239638, Sneha : +918709405374'

pattern = re.compile(r'91\B\d{10}')
matches = pattern.finditer(myStr)
for match in matches:
    print(match)
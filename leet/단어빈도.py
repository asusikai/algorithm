import re
from collections import Counter

paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]

paragraph = paragraph.lower()

paragraph = re.sub('[^\w]',' ',paragraph)

result = list()

for i in paragraph.split():
    if i not in banned:
        result.append(i)

count = Counter(result)

print((count.most_common(1)[0][0]))
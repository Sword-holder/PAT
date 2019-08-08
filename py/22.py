N = int(input())

title_table = {}
author_table = {}
key_words_table = {}
publisher_table = {}
year_table = {}

table_list = (title_table, author_table, key_words_table, publisher_table, year_table)

for i in range(N):
    id = input()
    title = input()
    author = input()
    key_words = input().split(' ')
    publisher = input()
    year = input()

    
    if title_table.get(title) == None:
        title_table[title] = []
    title_table[title].append(id)
    if author_table.get(author) == None:
        author_table[author] = []
    author_table[author].append(id)
    for word in key_words:
        if key_words_table.get(word) == None:
            key_words_table[word] = []
        key_words_table[word].append(id)
    if publisher_table.get(publisher) == None:
        publisher_table[publisher] = []
    publisher_table[publisher].append(id)
    if year_table.get(year) == None:
        year_table[year] = []
    year_table[year].append(id)

# 处理询问
M = int(input())
for i in range(M):
    query = input()
    print(query)
    query = query.split(': ')
    tag = int(query[0])
    if query[1] in table_list[tag - 1]:
        ids = []
        for id in table_list[tag - 1][query[1]]:
            ids.append(id)
        ids = sorted(ids)
        for id in ids:
            print(id)
    else:
        print('Not Found')

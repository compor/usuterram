def print_graph(dictmap, title=''):
    print('{0}'.format(title))

    for k, v in dictmap.items():
        line = '{0:5} -> '.format(str(k))
        line += ', '.join(str(e) for e in v)
        print(line)

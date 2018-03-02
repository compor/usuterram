#
#
#

from predecessors import predecessors
from dom_comp import dom_comp


def print_dictmap(dictmap, title=''):
    print('{0}'.format(title))

    for k, v in dictmap.items():
        line = '{0:5} -> '.format(str(k))
        line += ', '.join(str(e) for e in v)
        print(line)


if __name__ == "__main__":
    g1 = {
        'entry': {'b1'},
        'b1': {'b2', 'b3'},
        'b2': {'exit'},
        'b3': {'b4'},
        'b4': {'b5', 'b6'},
        'b5': {'exit'},
        'b6': {'b4'},
        'exit': {}
    }

    p = predecessors(g1)
    print_dictmap(p, title='predecessors')

    print('')

    d = dom_comp(g1, 'entry')
    print_dictmap(d, title='dominators')

#
#
#

from predecessors import predecessors
from dom_comp import dom_comp

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

if __name__ == "__main__":
    p = predecessors(g1)

    print('\nPredecessors')
    for k, v in p.iteritems():
        line = '{0:5} -> '.format(k)
        for e in v:
            line += '{0}, '.format(e)
        print(line)

    d = dom_comp(g1, 'entry')

    print('\nDominance')
    for k, v in d.iteritems():
        line = '{0:5} -> '.format(k)
        for e in v:
            line += '{0}, '.format(e)
        print(line)

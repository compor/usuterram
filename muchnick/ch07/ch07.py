#
#
#

from predecessors import predecessors
from dom_comp import dom_comp
from idom_comp import idom_comp
from postdominators import postdominators
from reverse_graph import reverse_graph
from utilities import print_graph

if __name__ == "__main__":
    # this graph is from muchnick ch07
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
    print_graph(p, title='\npredecessors')

    d = dom_comp(g1, 'entry')
    print_graph(d, title='\ndominators')

    idom = idom_comp(g1, 'entry')
    print_graph(idom, title='\nimmediate dominators')

    # this graph is from ferrante1987
    g2 = {
        'start': {'b1'},
        'b1': {'b2', 'b3'},
        'b2': {'b4', 'b5'},
        'b3': {'b5', 'b7'},
        'b4': {'b6'},
        'b5': {'b6'},
        'b6': {'b7'},
        'b7': {'stop'},
        'stop': {}
    }

    rg2 = reverse_graph(g2)
    print_graph(rg2, '\nreverse graph')

    pd2 = postdominators(g2, 'stop')
    print_graph(pd2, '\npost-dominators')

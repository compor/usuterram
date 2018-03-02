# algorithm 7.14
# DAG dominance calculation

from predecessors import predecessors

graph = {
    'entry': {'b1'},
    'b1': {'b2', 'b3'},
    'b2': {'exit'},
    'b3': {'b4'},
    'b4': {'b5', 'b6'},
    'b5': {'exit'},
    'b6': {'b4'},
    'exit': {}
}



# this encapsulates the following textual description:
# 1. node A dominates itself, or
# 2. node A has a single immediate predecessor, then it is dominated by it, or
# 3. node A has multiple immediate predecessors, then find the common
#    dominators of its predecessors, those will dominate it


def dom_comp(graph, root):
    nodes = set()
    dominators = {}
    preds = predecessors(graph)

    for k in graph.iterkeys():
        dominators[k] = {}
        nodes.add(k)

    for k in graph.iterkeys():
        dominators[k] = nodes

    dominators[root] = {root}

    changed = True
    while changed:
        changed = False
        for n in nodes - {root}:
            t = nodes.copy()
            for p in preds[n]:
                t &= dominators[p]
            d = {n} | t
            t = d ^ dominators[n]
            if len(t):
                changed = True
                dominators[n] = d

    return dominators


predecessors(graph)
dom_comp(graph, 'entry')

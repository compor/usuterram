# algorithm 7.14
# DAG dominance calculation
#

from predecessors import predecessors

# this encapsulates the following textual description:
# 1. node A dominates itself, or
# 2. node A has a single immediate predecessor, then it is dominated by it, or
# 3. node A has multiple immediate predecessors, then find the common
#    dominators of its predecessors, those will dominate it


def dom_comp(graph, root):
    nodes = set()
    dominators = {}
    preds = predecessors(graph)

    for k in graph.keys():
        dominators[k] = {}
        nodes.add(k)

    for k in graph.keys():
        dominators[k] = nodes

    dominators[root] = {root}

    changed = True
    while changed:
        changed = False
        for n in nodes - {root}:
            newDominators = nodes.copy()
            for p in preds[n]:
                newDominators &= dominators[p]
            newDominators |= {n}

            if len(newDominators ^ dominators[n]):
                changed = True
                dominators[n] = newDominators

    return dominators

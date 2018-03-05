# algorithm 7.15
# DAG immediate dominance calculation
#

from dom_comp import dom_comp


def idom_comp(graph, root):
    nodes = set()
    dominators = dom_comp(graph, root)
    idominators = dominators.copy()

    for k in dominators.keys():
        idominators[k] -= {k}
        nodes.add(k)

    for n in nodes - {root}:
        tmp = idominators[n].copy()
        for s in tmp:
            for t in tmp:
                if t == s:
                    continue
                if t in idominators[s]:
                    idominators[n] -= {t}

    return idominators

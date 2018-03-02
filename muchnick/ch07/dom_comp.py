# algorithm 7.14
# DAG dominance calculation

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


def predecessors(graph):
    preds = {}

    for k in graph.iterkeys():
        preds[k] = set()

    for k, v in graph.iteritems():
        for n in v:
            preds[n] |= {k}

    return preds


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

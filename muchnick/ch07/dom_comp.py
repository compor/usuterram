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

    print preds


def predecessors(graph):
    preds = {}

    for k in graph.iterkeys():
        preds[k] = set()

    for k, v in graph.iteritems():
        for n in v:
            preds[n] |= {k}

    return preds

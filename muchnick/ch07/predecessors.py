def predecessors(graph):
    preds = {}

    for k in graph.keys():
        preds[k] = set()

    for k, v in graph.items():
        for n in v:
            preds[n] |= {k}

    return preds

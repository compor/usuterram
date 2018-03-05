def reverse(graph):
    rgraph = {}

    for k in graph.keys():
        rgraph[k] = set()

    for k, v in graph.items():
        for n in v:
            rgraph[n] |= {k}

    return rgraph

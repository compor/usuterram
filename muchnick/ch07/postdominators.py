from dom_comp import dom_comp
from reverse_graph import reverse_graph


def postdominators(graph, root):
    return dom_comp(reverse_graph(graph), root)

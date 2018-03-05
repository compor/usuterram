from dom_comp import dom_comp
from reverse import reverse


def postdominators(graph, root):
    return dom_comp(reverse(graph), root)

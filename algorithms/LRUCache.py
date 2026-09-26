from collections.abc import Callable
from typing import Generic, TypeVar

T = TypeVar("T")
KT = TypeVar("KT")
VT = TypeVar("VT")


class Node(Generic[T]):
    def __init__(self, val: T):
        self.val: T = val
        self.next: Node[T] | None = None
        self.prev: Node[T] | None = None


class LRULinkedList(Generic[T]):
    def __init__(self):
        self.head: Node[T] | None = None
        self.tail: Node[T] | None = None

    def insert(self, new_node: Node[T]):
        # List is empty
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            return

        # Insert at head as MRU
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    def move_to_MRU(self, node: Node[T]):
        # Node already MRU or list empty
        if node.prev is None or self.head is None:
            return

        node.prev.next = node.next
        node.next = self.head
        self.head.prev = node

    def evict_LRU(self) -> Node[T] | None:
        if self.tail is None:
            return None

        if self.tail.prev is None:
            node = self.tail
            self.head = None
            self.tail = None
            return node

        self.tail.prev.next = None
        node = self.tail
        self.tail = node.prev
        return node


class LRUCache(Generic[KT, VT]):
    def __init__(self, max_capacity: int):
        self.max_capacity: int = max_capacity
        self.val_map: dict[KT, VT] = {}
        self.node_map: dict[KT, Node[KT]] = {}
        self.linked_list: LRULinkedList[KT] = LRULinkedList()

    def get(self, key: KT) -> VT | None:
        if key in self.val_map:
            node = self.node_map[key]
            self.linked_list.move_to_MRU(node)
            return self.val_map[key]

        return None

    def set(self, key: KT, val: VT):
        if key in self.val_map:
            self.val_map[key] = val
            node = self.node_map[key]
            self.linked_list.move_to_MRU(node)
            return

        # Evict LRU element if cache reached capacity
        if len(self.val_map) >= self.max_capacity:
            node = self.linked_list.evict_LRU()
            if node:
                del self.val_map[node.val]
                del self.node_map[node.val]

        # Insert into cache
        node = Node(key)
        self.val_map[key] = val
        self.node_map[key] = node
        self.linked_list.insert(node)


def f(x: int) -> int:
    return x * x


IT = TypeVar("IT")
OT = TypeVar("OT")


def memo(f: Callable[[IT], OT]) -> Callable[[IT], OT]:
    cache: LRUCache[IT, OT] = LRUCache(128)

    def wrapper(input: IT) -> OT:
        output = cache.get(input)
        if output:
            return output

        output = f(input)
        cache.set(input, output)
        return output

    return wrapper


def main():
    g = memo(f)
    print(g(1))
    print(g(2))
    print(g(3))
    print(g(4))
    print(g(5))
    print(g(1))
    print(g(2))
    print(g(3))
    print(g(4))
    print(g(5))


if __name__ == "__main__":
    main()

using System;
using System.Collections.Generic;

namespace DataStructures {

    public class LinkedList<T>
    {
        private Node<T> Head;
        public int Length { get; private set; }

        //Constructors
        public LinkedList() {
            Head = null;
            Length = 0;
        }
        public LinkedList(T data) {
            Head = new Node<T>(data);
            Length = 1;
        }
        public LinkedList(Node<T> node) {
            Head = node;
            Length = 1;
            var current = Head;
            while(current.Next != null) {
                current = current.Next;
                Length += 1;
            }
        }

        //Insertion Methods
        public Node<T> Insert(Node<T> node) {
            var current = Head;
            while(current.Next != null) {
                current = current.Next;
            }
            current.Next = node;
            Length += 1;
            return Head;
        }
        public Node<T> Insert(T data) {
            Node<T> node = new Node<T>(data);
            return Insert(node);
        }
        public Node<T> Insert(List<Node<T>> list) {
            foreach(var node in list) {
                Insert(node);
            }
            return Head;
        }
        public Node<T> Insert(List<T> list) {
            foreach(var data in list) {
                Insert(data);
            }
            return Head;
        }
        public Node<T> InsertAt(Node<T> node, int index) {
            var current = Head;
            for(; index > 0 && current.Next != null; index--) {
                current = current.Next;
            }
            var temp = current.Next;
            current.Next = node;
            node.Next = temp;
            return Head;
        }

        //Deletion Methods
        public Node<T> Delete(Node<T> node) {
            var current = Head;
            var parent = Head;
            while(current != null) {
                if (current.Equals(node)) {
                    if(current.Equals(Head)) {
                        Head = current.Next;
                    } else {
                        parent.Next = current.Next;
                    }
                    Length -= 1;
                    return Head;
                }
                parent = current;
                current = current.Next;
            }
            Length -= 1;
            return Head;
        }
        public Node<T> Delete(T data) {
            var current = Head;
            var parent = Head;
            while(current != null) {
                if (current.Data.Equals(data)) {
                    if(current.Equals(Head)) {
                        Head = current.Next;
                    } else {
                        parent.Next = current.Next;
                    }
                    Length -= 1;
                    return Head;
                }
                parent = current;
                current = current.Next;
            }
            Length -= 1;
            return Head;
        }

        //Accessor Methods
        public Node<T> this[int i] {
            get {
                return At(i);
            }
        }
        public Node<T> At(int i) {
            if(i + 1 > Length)
                throw new System.IndexOutOfRangeException("Indice out of range");

            var current = Head;
            for(; i > 0; i--) {
                current = current.Next;
            }
            return current;
        }

        //Misc Methods
        public Node<T> Reverse() {
            Node<T> parent = null;
            Node<T> current = Head;
            Node<T> next = null;

            while(current != null) {
                next = current.Next;
                current.Next = parent;
                parent = current;
                current = next;
            }
            return Head = parent;
        }
        public override string ToString(){
            string buffer = "";
            var current = Head;
            while(current != null) {
                buffer = buffer + current.Data;
            }
            return buffer;
        }
        public void Print() {
            Console.WriteLine(ToString());
        }
    }

    public class BinaryTree<T> {
        private Node<T> Root;
        public int Depth { get; private set; }
        public int Count { get; private set; }

        //Constructors
        public delegate int Compare(T a, T b);
        public Compare Comp { get; private set; }
        public BinaryTree(Compare compare_method) {
            Comp = compare_method;
        }
        public BinaryTree(Node<T> root) {
            Root = root;
        }
        public BinaryTree(Node<T> root, Compare compare_method) {
            Root = root;
            Comp = compare_method;
        }

        //Insert Methods
        public Node<T> Insert(Node<T> node) {
            if (Root == null) {
                return Root = node;
            }
            var current = Root;
            while(current != null) {
                if(Comp(node.Data, current.Data) < 0) {
                    //Left
                    if(current.Left != null) {
                        current = current.Left;
                        continue;
                    } else {
                        current.Left = node;
                        return Root;
                    }
                } else {
                    //Right
                    if(current.Right != null) {
                        current = current.Right;
                        continue;
                    } else {
                        current.Right = node;
                        return Root;
                    }
                }
            }
            return null;
        }
        public Node<T> Insert(T data) {
            var node = new Node<T>(data);
            return Insert(node);
        }
        //Delete Methods

        //Accessor Methods

        //Misc Methods
        public void Print() {
            PrintTree(Root);
        }
        private void PrintTree(Node<T> current, int depth=0) {
            if (current == null) {
                return;
            }
            PrintTree(current.Left, depth + 1);

            Console.WriteLine(new String(' ', depth) + current.Data);

            PrintTree(current.Right, depth + 1);
        }
    }
}

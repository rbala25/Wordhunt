package com.rishibala;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

class TrieNode {
    TrieNode[] letters = new TrieNode[26];
    boolean endOfWord;
    List<Integer> positions;

    TrieNode() {
        this.positions = new ArrayList<>();
    }
}

public class DictionaryTrie {
    private TrieNode root;

    public DictionaryTrie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int index = c - 'A';
            if (node.letters[index] == null) {
                node.letters[index] = new TrieNode();
            }
            node = node.letters[index];
        }
        node.endOfWord = true;
    }

    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for (char c : prefix.toCharArray()) {
            int index = c - 'A';
            if (node.letters[index] == null) {
                return false;
            }
            node = node.letters[index];
        }
        return true;
    }

    public boolean search(String word) {
        TrieNode node = root;
        for (char c : word.toCharArray()) {
            int index = c - 'A';
            if (node.letters[index] == null) {
                return false;
            }
            node = node.letters[index];
        }
        return node.endOfWord;
    }

    public static DictionaryTrie loadDictionary(String filePath) throws IOException {
        DictionaryTrie trie = new DictionaryTrie();
        BufferedReader reader = new BufferedReader(new FileReader(filePath));
        String word;
        while ((word = reader.readLine()) != null) {
            trie.insert(word.trim());
        }
        reader.close();
        return trie;
    }
}

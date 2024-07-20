package com.rishibala;

import java.io.IOException;
import java.util.*;

public class OnlyWords {
    private static final int SIZE = 4;
    private static DictionaryTrie trie;

//    private static SerialPort serialPort;


    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter 16 letters (uppercase):");
        String letters = scanner.nextLine().toUpperCase();

        if (letters.length() != 16) {
            System.out.println("Please enter exactly 16 letters.");
            return;
        }

        trie = DictionaryTrie.loadDictionary("/Users/rishibala/Desktop/WordHuntBot/collins2019.txt");
        char[][] board = new char[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = letters.charAt(i * SIZE + j);
            }
        }

        List<String> finalWords = new ArrayList<>();
        System.out.println();
        Map<String, List<Integer>> allWords = findWords(board);
        for (String word : allWords.keySet()) {
            if(word.length() < 3) {
                continue;
            }
            finalWords.add(word);
//            foundWords.put(word, allWords.get(word));
        }
        String[] words = new String[finalWords.size()];
        words = finalWords.toArray(words);
        Arrays.sort(words, Comparator.comparing(String::length));
        Collections.reverse(Arrays.asList(words));

//        for(String word : words) {
//            System.out.println(word);
//        }

        for(String word : words) {
            System.out.println(word);
        }

    }

    private static Map<String, List<Integer>> findWords(char[][] board) {
        Map<String, List<Integer>> foundWords = new LinkedHashMap<>();
        boolean[][] visited = new boolean[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                findWordsHelper(board, visited, i, j, "", new ArrayList<>(), foundWords);
            }
        }
        return foundWords;
    }

    private static void findWordsHelper(char[][] board, boolean[][] visited, int i, int j, String prefix, List<Integer> positions, Map<String, List<Integer>> foundWords) {
        if (i < 0 || j < 0 || i >= SIZE || j >= SIZE || visited[i][j]) {
            return;
        }

        prefix += board[i][j];
        positions.add(i * SIZE + j + 1);

        if (!trie.startsWith(prefix)) {
            positions.remove(positions.size() - 1);
            return;
        }

        visited[i][j] = true;
        if (trie.search(prefix)) {
            foundWords.put(prefix, new ArrayList<>(positions));
        }

        int[] rowOffsets = {-1, -1, -1, 0, 0, 1, 1, 1};
        int[] colOffsets = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int k = 0; k < 8; k++) {
            findWordsHelper(board, visited, i + rowOffsets[k], j + colOffsets[k], prefix, positions, foundWords);
        }

        visited[i][j] = false;
        positions.remove(positions.size() - 1);
    }

//    private static void sendToArduino(Map<String, List<Integer>> foundWords) {
//        initializeSerial("/dev/tty.usbmodem1101");
//
//        // Send found words and their positions to the Arduino
//        for (Map.Entry<String, List<Integer>> entry : foundWords.entrySet()) {
//            String word = entry.getKey();
//            List<Integer> positions = entry.getValue();
//            sendWordToArduino(word, positions);
//        }
//
//        closeSerial();
//    }

}

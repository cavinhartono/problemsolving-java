package Wildcard;

import java.util.Scanner;

class App {
  private static Scanner ip = new Scanner(System.in);

  public static void main(String[] args) {
    String filter = ip.nextLine();

    String[] Filters = new String[ip.nextInt()];
    for (int i = 0; i <= Filters.length; i++) {
      Filters[i] = ip.nextLine();
    }

    for (String f : Filters) {
      System.out.println(f);
    }

    System.out.println(filter.split("*"));
  }
}
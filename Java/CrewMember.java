package Other;

import java.util.*;

public class CrewMember {
    private static CrewMember[] crewMembers;
    private static int totalCrewMembers = 0;

    private String name;
    private int experienceLevel;

    CrewMember(String name, int experienceLevel) {
        this.name = name;
        this.experienceLevel = experienceLevel;
        totalCrewMembers++;
    }

    static void calculateAverageExperience() {
        int totalEXP = 0;
        for (CrewMember currentMember : crewMembers) {
            totalEXP += currentMember.experienceLevel;
        }
        double avgEXP = (double) (totalEXP / totalCrewMembers);
        System.out.println("Average = " + avgEXP);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input: Number of Crew Members
        System.out.print("No of crew members: ");
        int numberOfCrewMembers = scanner.nextInt();

        // Input: Crew Member Details
        for (int i = 0; i < numberOfCrewMembers; i++) {

            System.out.println("Crew Member " + (i + 1) + ":");

            System.out.print("Name: ");
            String name = scanner.next();
            System.out.print("Experience Level: ");
            int experienceLevel = scanner.nextInt();
            crewMembers[i] = new CrewMember(name, experienceLevel);
        }

        // Output: Calculate and Display Average Experience
        CrewMember.calculateAverageExperience();
        scanner.close();
    }
}

import java.util.Scanner;

public class AccountTest {
    public static void main(String[] args) {
        // 创建10个账户
        Account[] accounts = new Account[10];
        for (int i = 0; i < 10; i++) {
            accounts[i] = new Account(i, 100);
        }

        Scanner input = new Scanner(System.in);

        while (true) {
            // 提示用户输入id
            System.out.print("Enter an id: ");
            int id = input.nextInt();

            // 验证id
            while (id < 0 || id > 9) {
                System.out.print("Enter a correct id: ");
                id = input.nextInt();
            }

            // 主菜单循环
            while (true) {
                // 显示主菜单
                System.out.println("\nMain menu");
                System.out.println("1: check balance");
                System.out.println("2: withdraw");
                System.out.println("3: deposit");
                System.out.println("4: exit");
                System.out.print("Enter a choice: ");
                int choice = input.nextInt();

                // 处理用户选择
                switch (choice) {
                    case 1:
                        System.out.printf("The balance is %.1f\n", accounts[id].getBalance());
                        break;
                    case 2:
                        System.out.print("Enter an amount to withdraw: ");
                        double withdrawAmount = input.nextDouble();
                        accounts[id].withdraw(withdrawAmount);
                        break;
                    case 3:
                        System.out.print("Enter an amount to deposit: ");
                        double depositAmount = input.nextDouble();
                        accounts[id].deposit(depositAmount);
                        break;
                    case 4:
                        break;
                    default:
                        System.out.println("Invalid choice. Please try again.");
                }

                // 如果用户选择退出，跳出主菜单循环
                if (choice == 4) {
                    break;
                }
            }
        }
    }

}

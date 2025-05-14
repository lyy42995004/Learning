
public class AccountTest {
    public static void main(String[] args) {
        // 设置年利率
        Account.setAnnualInterestRate(1.5);
        // 创建账户
        NewAccount account = new NewAccount("George", 1122, 1000);

        // 存款操作
        account.deposit(30);
        account.deposit(40);
        account.deposit(50);
        // 取款操作
        account.withdraw(5);
        account.withdraw(2);

        // 打印账户信息
        System.out.println("Account Holder Name: " + account.getName());
        System.out.println("Interest Rate: " + Account.getAnnualInterestRate() + "%");
        System.out.println("Balance: $" + account.getBalance());

        System.out.println("\nTransactions:");
        for (Transaction transaction : account.getTransactions()) {
            System.out.println("Date: " + transaction.getDate());
            System.out.println("Type: " + (transaction.getType() == 'D'? "Deposit" : "Withdrawal"));
            System.out.println("Amount: $" + transaction.getAmount());
            System.out.println("Balance after transaction: $" + transaction.getBalance());
            System.out.println("Description: " + transaction.getDescription());
            System.out.println("-------------------");
        }
    }
}
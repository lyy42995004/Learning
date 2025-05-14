
import java.util.ArrayList;

// 新的Account类，继承旧的Account类
class NewAccount extends Account {
    private String name;
    private ArrayList<Transaction> transactions = new ArrayList<>();

    public NewAccount(String name, int id, double balance) {
        super(id, balance);
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public void withdraw(double amount) {
        double oldBalance = getBalance();
        super.withdraw(amount);
        if (getBalance() != oldBalance) {
            String desc = "Withdraw $" + amount;
            Transaction transaction = new Transaction('W', amount, getBalance(), desc);
            transactions.add(transaction);
        }
    }

    @Override
    public void deposit(double amount) {
        double oldBalance = getBalance();
        super.deposit(amount);
        if (getBalance() != oldBalance) {
            String desc = "Deposit $" + amount;
            Transaction transaction = new Transaction('D', amount, getBalance(), desc);
            transactions.add(transaction);
        }
    }

    public ArrayList<Transaction> getTransactions() {
        return transactions;
    }
}

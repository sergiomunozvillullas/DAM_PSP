// Clase HiloParImpar extiende Thread
public class HiloParImpar extends Thread {
    private int tipo;

    // Constructor de la clase
    HiloParImpar(int tipo) {
        this.tipo = tipo;
    }

    // Método run -> funcionalidad del hilo
    public void run() {
        if (tipo == 1) {
            for (int i = 1; i <= 100; i ++) {
            if(i%2==0){
            System.out.println("tipo 1: " + i);
            }
                
            }
        } else if (tipo == 2) {
            for (int i = 101; i <= 200; i ++) {
            
            if(i%2!=0){
            System.out.println("tipo 2: " + i);
            }
            }
        }
    }

    public static void main(String[] args) {
        HiloParImpar par = new HiloParImpar(1);
        HiloParImpar impar = new HiloParImpar(2);
        impar.start();
        par.start();
        
    }
}//main


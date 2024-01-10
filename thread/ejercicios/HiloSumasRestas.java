public class HiloSumasRestas implements Runnable {
    private static int numero = 1000;
    private int numveces;
    private String operacion;

    // Constructor de la clase
    public HiloSumasRestas(int numveces, String operacion) {
        this.numveces = numveces;
        this.operacion = operacion;
    }

    // Incrementará numero el numvece indicado
    public void incrementar(int numveces) {
        for (int i = 0; i < numveces; i++) {
            numero++;
        }
    }

    // Decrementará numero el numvece indicado
    public void decrementar(int numveces) {
        for (int i = 0; i < numveces; i++) {
            numero--;
        }
    }

  
    public void run() {
        //while(numero!=900){
        if(operacion=="+"){
        incrementar(numveces);
         System.out.println("Resultado final: " + numero);
        }
        
        if(operacion=="-"){
      	decrementar(numveces);
      	 System.out.println("Resultado final: " + numero);
        }
        
        //}
        
    }

    public static void main(String[] args) {
        HiloSumasRestas hs1 = new HiloSumasRestas(100, "+");
        HiloSumasRestas hr2 = new HiloSumasRestas(100, "-");
        HiloSumasRestas hs3 = new HiloSumasRestas(1, "+");
        HiloSumasRestas hr4 = new HiloSumasRestas(1, "-");


        Thread threadSuma1 = new Thread(hs1);
        Thread threadResta2 = new Thread(hr2);
        Thread threadSuma3 = new Thread(hs3);
        Thread threadResta4 = new Thread(hr4);

        threadSuma1.start();
        threadResta2.start();
        threadSuma3.start();
        threadResta4.start();


        System.out.println("Resultado final: " + numero);
    }
}


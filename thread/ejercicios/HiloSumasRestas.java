// Clase HiloParImpar extiende Thread
public class HiloSumasRestas extends Thread {
    private int numero;

	//Constructor de la clase
	public HiloSumasRestas (int numveces, String operacion)
	{
	this.tipo = tipo;
	this.operacion = operacion;

	}
	//Incrementará numero el numvece indicado
	public int incrementar (int numveces)
	{
            
            System.out.println("tipo 1: " + i);

                
         
	}
	//Decrementará numero el numvece indicado
	public int decrementar (int numveces)
	{
	}


    // Método run -> funcionalidad del hilo
    public void run() {
        
        
        if(operacion=="+"){
        incrementar(100);
        incrementar(1);
        }
        
        if(operacion=="-"){
        decrementar(100);
        decrementar(1);
        }
        


 
    }

    public static void main(String[] args) {
        HiloSumasRestas h1 = new HiloSumasRestas(1,"+");
        HiloSumasRestas h2 = new HiloSumasRestas(2,"+");
        HiloSumasRestas h3 = new HiloSumasRestas(1,"-");
        HiloSumasRestas h4 = new HiloSumasRestas(2,"-");
        
        h1.start();
        h2.start();
        h3.start();
        h4.start();
        
    }
}//main


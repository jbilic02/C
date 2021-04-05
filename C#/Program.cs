using System;


namespace c_
{
    class Game{
        public enum Hand {Kamen = 1, Skare, Papir};
        public enum Out {Pobjeda, Izgubljeno, Izjednaceno};

        public Hand IgracevPotez { get; set; }
        public Hand KompPotez { get; set; }
        public char KorisnikOdabir { get; set; } 


        public Hand getOdabir(){
                
            Console.WriteLine("K- kamen");
            Console.WriteLine("S- skare");
            Console.WriteLine("P- papir");
            KorisnikOdabir = Convert.ToChar(Console.ReadLine());
            

            switch(Char.ToUpper(KorisnikOdabir))
            {
                case 'K':
                    IgracevPotez = Hand.Kamen;
                    break;
                case 'S':
                    IgracevPotez = Hand.Skare;
                    break;
                case 'P':
                    IgracevPotez = Hand.Papir;
                    break;
                default:
                    throw new Exception("krivi unos");
            }
            return IgracevPotez;
        }

        public void PlayGame()
        {
            var rand = new Random();

            getOdabir();
            KompPotez = (Hand)rand.Next(1,4);
            Console.WriteLine("vas odabir je: {0}", IgracevPotez);
            Console.WriteLine("komp odabir: {0}", KompPotez);

            
            
            if(Ispis() == Out.Pobjeda){
                
                Console.WriteLine("{0} > {1} \t pobjeda", IgracevPotez, KompPotez);
            }
            else if (Ispis() == Out.Izgubljeno)
            {
                
                Console.WriteLine("{0} > {1} \t izgubljeno", KompPotez, IgracevPotez);
            }    
            else 
                Console.WriteLine("izjednaceno");
            
            
            
        }

        public Out Ispis()
        {
            if (IgracevPotez == Hand.Kamen && KompPotez == Hand.Skare)
                return Out.Pobjeda;
            else if (IgracevPotez == Hand.Papir && KompPotez == Hand.Kamen)
                return Out.Pobjeda;
            else if (IgracevPotez == Hand.Skare && KompPotez == Hand.Papir)
                return Out.Pobjeda;
            else if (IgracevPotez == Hand.Skare && KompPotez == Hand.Kamen)
                return Out.Izgubljeno;
            else if (IgracevPotez == Hand.Kamen && KompPotez == Hand.Papir)
                return Out.Izgubljeno;
            else if (IgracevPotez == Hand.Papir && KompPotez == Hand.Skare)
                return Out.Izgubljeno;
            
            return Out.Izjednaceno;
        }


    }

    class Program
    {
        static void Main(string[] args)
        {
           Game game = new Game();
           
           Console.WriteLine("unesi broj igranja");
           int a = Convert.ToInt32(Console.ReadLine());
           for(int i=0; i<a; i++){
               game.PlayGame();
               
           }
           

        }
    }
}

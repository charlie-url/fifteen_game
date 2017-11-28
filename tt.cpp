#include "std_lib_facilities_5.h"
#include "Window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Simple_window.h"
#include <unistd.h>

struct Game_screen : Graph_lib::Window {


Button quit_button;
Button ten;
Button twenty;
Button forty;
Button eighty;
Vector_ref<Button> buttons;
Vector_ref<Text> texts;
vector<int> numbers; 
int difficulty;

//vector <int> numbers_s;
//vector<int> x_num{100,200,300,400,100,200,300,400,100,200,300,400,100,200,300};
//vector<int> y_num{200,200,200,200,300,300,300,300,400,400,400,400,500,500,500};


vector<int> x_num{100,100,100,100,200,200,200,200,300,300,300,300,400,400,400,400};
vector<int> y_num{200,300,400,500,200,300,400,500,200,300,400,500,200,300,400,500};
int y;





Game_screen(Point xy, int w, int h, const string& title)
		:Window{ xy,w,h,title },
		quit_button{ Point{ 70,0 }, 70, 20, "Quit",[](Address, Address pw) {reference_to<Game_screen>(pw).quit();} },
		ten {Point(200,50), 320, 100, "10", [](Address, Address pw) {reference_to<Game_screen>(pw).ten_game();} },
	    twenty{Point(200,150), 320, 100, "20", [](Address, Address pw) {reference_to<Game_screen>(pw).twenty_game();} },
        forty{Point(200,250), 320, 100, "40", [](Address, Address pw) {reference_to<Game_screen>(pw).forty_game();} },
        eighty {Point(200,350), 320, 100, "80", [](Address, Address pw) {reference_to<Game_screen>(pw).eighty_game();} }
	{
		attach(quit_button);
		attach(ten);
		attach(twenty);
		attach(forty);
		attach(eighty);
	}


		void quit(){
			hide();
   		}
   

		void stop(){
		Simple_window win3(Point(200,200),100,100,"game over"); 
		Text t {Point{30,50},"Game over"}; 
		win3.attach(t);
		win3.wait_for_button();
		Fl::redraw();
		}


        void move_count(int y){

        for (int i=0;i<10;i++){
        texts.push_back(new Text {Point{50,50}, to_string(i)});
       
        }
         detach(texts[y]);
         attach(texts[y]);
       //  sleep(1);
        // 
         Fl::redraw();
        }


		void compare(int temp){
		int x_correct=x_num[temp];
		int y_correct=y_num[temp];	

        cout<<"co x is: "<<x_correct<<endl;
        cout<<"co y is: "<<y_correct<<endl;
	    int wrong_move=16;
	    for(int i=0;i<x_num.size();i++){
		if((x_correct==buttons[temp].loc.x)&& (y_correct==buttons[temp].loc.y)){
		wrong_move--;
	     	}
		else 		
		wrong_move++; 
       	 }
    //    cout<<wrong_move;
		 } 


void tile(int x){

//cout<<"current x is: "<<buttons[x].loc.x<<endl;
//cout<<"current y is: "<<buttons[x].loc.y<<endl;

 
for(int i=0;i<15;i++){
   
		if(numbers[i]==0){	  	
        
		if((buttons[i].loc.x-buttons[x].loc.x)==100&& (buttons[i].loc.y-buttons[x].loc.y)==0){
			
           	buttons[i].move(-100,0);  
          	buttons[x].move(100,0);
      //    	cout<<"current x is: "<<buttons[x].loc.x<<endl;
       //   	cout<<"current y is: "<<buttons[x].loc.y<<endl;
       //     compare(x);

          	y--;

            if(y==0){stop();}
           
		 	} 
        
        	else if ((buttons[x].loc.x-buttons[i].loc.x==100)&&(buttons[i].loc.y-buttons[x].loc.y)==0) {
       		 
        	 buttons[i].move(100,0);  
             buttons[x].move(-100,0);
        	 y--;
      //  	 compare(x);
     //       cout<<"current x is: "<<buttons[x].loc.x<<endl;
      //    	cout<<"current y is: "<<buttons[x].loc.y<<endl;


             if(y==0){stop();}
        	}

        else if ((buttons[x].loc.x-buttons[i].loc.x==0)&&(buttons[i].loc.y-buttons[x].loc.y)==100 ){
        	
         	  buttons[i].move(0,-100);
              buttons[x].move(0,100);
           	  y--;
       //    	  cout<<"current x is: "<<buttons[x].loc.x<<endl;
         //     cout<<"current y is: "<<buttons[x].loc.y<<endl;
         //  	   compare(x); 
          if(y==0){stop();}
            }
        
        else if ((buttons[x].loc.x-buttons[i].loc.x==0)&&(buttons[x].loc.y-buttons[i].loc.y)==100 ){
        	 
             buttons[i].move(0,100);
             buttons[x].move(0,-100);
             y--;
    //         cout<<"current x is: "<<buttons[x].loc.x<<endl;
   //       	 cout<<"current y is: "<<buttons[x].loc.y<<endl;
            compare(x);
            if(y==0){stop();}
        }
		    cout<<y<<endl;

           move_count(y);
           
	    }	
	   	
      
}
}	



void eighty_game(){
y=80;
detach(eighty);
detach(twenty);
detach(ten);
detach(forty);

numbers={ 0, 15, 3, 4, 12, 14, 7, 8, 11, 10, 6, 5, 13, 9, 2, 1 };


					buttons.push_back(new Button {Point(100,200), 100, 100, "", [](Address, Address pw) { reference_to<Game_screen>(pw).tile(0); }});
            
                    buttons.push_back(new Button {Point(200,200), 100, 100, to_string(12), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(1); }});

					buttons.push_back(new Button {Point(300,200), 100, 100, to_string(11), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(2); }});

                    buttons.push_back(new Button {Point(400,200), 100, 100, to_string(13), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(3); }});
 
				
					buttons.push_back(new Button {Point(100,300), 100, 100, to_string(15), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(4); }});

 					buttons.push_back(new Button {Point(200,300), 100, 100, to_string(14), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(5); }});
					
                    buttons.push_back(new Button {Point(300,300), 100, 100, to_string(10), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(6); }});

                    buttons.push_back(new Button {Point(400,300), 100, 100, to_string(9), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(7); }});


               
					buttons.push_back(new Button {Point(100,400), 100, 100, to_string(3), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(8); }});
            
                	buttons.push_back(new Button {Point(200,400), 100, 100, to_string(7), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(9); }});

 					buttons.push_back(new Button {Point(300,400), 100, 100, to_string(6), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(10); }});
					
			    	buttons.push_back(new Button {Point(400,400), 100, 100, to_string(2), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(11); }});
				


					buttons.push_back(new Button {Point(100,500), 100, 100, to_string(4), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(12); }});
            
             		buttons.push_back(new Button {Point(200,500), 100, 100, to_string(8), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(13); }});
					
                    buttons.push_back(new Button {Point(300,500), 100, 100, to_string(5), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(14); }});
                
					buttons.push_back(new Button {Point(400,500), 100, 100, to_string(1), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(15); }});
            
            


                    for (int i=0;i<buttons.size();i++){
				    attach(buttons[i]);
                     }



}


void forty_game(){
y=40;
detach(eighty);
detach(twenty);
detach(ten);
detach(forty);

numbers={ 4, 3, 9, 13, 8, 0, 2, 14, 12, 7, 1, 5, 15, 11, 10, 6 };

					buttons.push_back(new Button {Point(100,200), 100, 100, to_string(4), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(0); }});
            
                    buttons.push_back(new Button {Point(200,200), 100, 100, to_string(8), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(1); }});

					buttons.push_back(new Button {Point(300,200), 100, 100, to_string(12), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(2); }});

                    buttons.push_back(new Button {Point(400,200), 100, 100, to_string(15), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(3); }});
 
				
					buttons.push_back(new Button {Point(100,300), 100, 100, to_string(3), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(4); }});

 					buttons.push_back(new Button {Point(200,300), 100, 100, "", [](Address, Address pw) { reference_to<Game_screen>(pw).tile(5); }});
					
                    buttons.push_back(new Button {Point(300,300), 100, 100, to_string(7), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(6); }});

                    buttons.push_back(new Button {Point(400,300), 100, 100, to_string(11), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(7); }});


               
					buttons.push_back(new Button {Point(100,400), 100, 100, to_string(9), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(8); }});
            
                	buttons.push_back(new Button {Point(200,400), 100, 100, to_string(2), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(9); }});

 					buttons.push_back(new Button {Point(300,400), 100, 100, to_string(1), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(10); }});
					
			    	buttons.push_back(new Button {Point(400,400), 100, 100, to_string(10), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(11); }});
				


					buttons.push_back(new Button {Point(100,500), 100, 100, to_string(13), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(12); }});
            
             		buttons.push_back(new Button {Point(200,500), 100, 100, to_string(14), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(13); }});
					
                    buttons.push_back(new Button {Point(300,500), 100, 100, to_string(5), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(14); }});
                
					buttons.push_back(new Button {Point(400,500), 100, 100, to_string(6), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(15); }});
            
            


                    for (int i=0;i<buttons.size();i++){
				    attach(buttons[i]);
                     }

                     }





void twenty_game(){
y=20;
detach(eighty);
detach(forty);
detach(twenty);
detach(ten);

numbers={ 1, 5, 9, 13, 6, 0, 10, 15, 3, 2, 14, 12, 4, 11, 7, 8 };
					buttons.push_back(new Button {Point(100,200), 100, 100, to_string(1), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(0); }});
            
                    buttons.push_back(new Button {Point(200,200), 100, 100, to_string(6), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(1); }});

					buttons.push_back(new Button {Point(300,200), 100, 100, to_string(3), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(2); }});

                    buttons.push_back(new Button {Point(400,200), 100, 100, to_string(4), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(3); }});
 
				
					buttons.push_back(new Button {Point(100,300), 100, 100, to_string(5), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(4); }});

 					buttons.push_back(new Button {Point(200,300), 100, 100, "", [](Address, Address pw) { reference_to<Game_screen>(pw).tile(5); }});
					
                    buttons.push_back(new Button {Point(300,300), 100, 100, to_string(2), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(6); }});

                    buttons.push_back(new Button {Point(400,300), 100, 100, to_string(11), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(7); }});


               
					buttons.push_back(new Button {Point(100,400), 100, 100, to_string(9), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(8); }});
            
                	buttons.push_back(new Button {Point(200,400), 100, 100, to_string(10), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(9); }});

 					buttons.push_back(new Button {Point(300,400), 100, 100, to_string(14), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(10); }});
					
			    	buttons.push_back(new Button {Point(400,400), 100, 100, to_string(7), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(11); }});
				


					buttons.push_back(new Button {Point(100,500), 100, 100, to_string(13), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(12); }});
            
             		buttons.push_back(new Button {Point(200,500), 100, 100, to_string(15), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(13); }});
					
                    buttons.push_back(new Button {Point(300,500), 100, 100, to_string(12), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(14); }});
                
					buttons.push_back(new Button {Point(400,500), 100, 100, to_string(8), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(15); }});
            
            


                    for (int i=0;i<buttons.size();i++){
				    attach(buttons[i]);
                     }
                  }



void ten_game(){
y=10;
detach(eighty);
detach(forty);
detach(ten);
detach(twenty);
numbers={ 1, 5, 9, 13, 2, 6, 10, 14, 3, 12, 0, 8, 4, 7, 15, 11 };

buttons.push_back(new Button {Point(100,200), 100, 100, to_string(1), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(0); }});
            
                    buttons.push_back(new Button {Point(200,200), 100, 100, to_string(2), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(1); }});

					buttons.push_back(new Button {Point(300,200), 100, 100, to_string(3), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(2); }});

                    buttons.push_back(new Button {Point(400,200), 100, 100, to_string(4), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(3); }});
 
				
					buttons.push_back(new Button {Point(100,300), 100, 100, to_string(5), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(4); }});

 					buttons.push_back(new Button {Point(200,300), 100, 100, to_string(6), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(5); }});
					
                    buttons.push_back(new Button {Point(300,300), 100, 100, to_string(12), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(6); }});

                    buttons.push_back(new Button {Point(400,300), 100, 100, to_string(7), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(7); }});


               
					buttons.push_back(new Button {Point(100,400), 100, 100, to_string(9), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(8); }});
            
                	buttons.push_back(new Button {Point(200,400), 100, 100, to_string(10), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(9); }});

 					buttons.push_back(new Button {Point(300,400), 100, 100, "", [](Address, Address pw) { reference_to<Game_screen>(pw).tile(10); }});
					
			    	buttons.push_back(new Button {Point(400,400), 100, 100, to_string(15), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(11); }});
				


					buttons.push_back(new Button {Point(100,500), 100, 100, to_string(13), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(12); }});
            
             		buttons.push_back(new Button {Point(200,500), 100, 100, to_string(14), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(13); }});
					
                    buttons.push_back(new Button {Point(300,500), 100, 100, to_string(8), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(14); }});
                
					buttons.push_back(new Button {Point(400,500), 100, 100, to_string(11), [](Address, Address pw) { reference_to<Game_screen>(pw).tile(15); }});
            for (int i=0;i<buttons.size();i++){
				attach(buttons[i]);
           }
            

	}









};



	int main() {
		try {
			Game_screen splash(Point(0, 0), 720, 720, "Game Screen");
//			//splash.wait_for_button();
			return gui_main();

		}
		catch (exception& e) {
			cerr << "error:" << e.what() << endl;
			keep_window_open();
			return 1;
		}
		catch (...) {
			cerr << "Oops, unknown exception!" << endl;
			keep_window_open();
			return 2;
		}
	}
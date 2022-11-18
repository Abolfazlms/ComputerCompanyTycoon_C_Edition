#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void guide(void);//prototype for the guide function for game
int price(int,int);//prototype for price of product function
int computer_price =0;//global scope for computer price
int profit=0;//global scope for profit
/*save the statistics of company*/
struct statistics
{
    int money;
    int customer;
    int year;

};
/*save the number of purchased parts*/
struct computer_price
{
    char name[20];
    int computer_case;
    int mother_board;
    int cpu;
    int ram;
    int graphic_card;
    int hard_drive;
    int cd_rom;
    int monitor;
    int price;
    int profit;
};
main()
{
    char company_name[20];//the name of computer company
    struct statistics st;//the structure definition
    struct computer_price cp[10000];//the product information
    st.money=1000;//first budget charge
    st.year=1;//first level or first year
    st.customer=10;//first company customers
    int i=0;//save the number of built computers
    int Exp=0;//Experience

    printf("\n");
    printf("Welcome to the computer's company tycoon!\n");
    printf("\n");

    //get the name of computer's company

    printf("Enter your computer's company name : ");
    gets(&company_name);
    printf("\n");

    printf("Welcome to the %s computer's company !",company_name);
    printf("\n");

    /* start the game */

    while(1)
    {
        int menu_select=0;//the player's selected section in main menu
        int store_select=0;//the player's selected section in store
        if(Exp==st.year*25)
        {
            st.year++;
        }
        printf("\n");
        printf("**********************************************************\n");
        printf("\n");
        printf("1- Company Statistics\n");
        printf("2- Computer's Factory\n");
        printf("3- Store\n");
        printf("4- History of Computers\n");
        printf("5- Hardware sell\n");
        printf("6- Guide\n");
        printf("7- Exit\n");
        printf("\n");
        printf("Select a section : ");
        scanf("%d",&menu_select);
        printf("\n");

        if(menu_select==1)
        {
            printf("**********************************************************\n");
            printf("\n");
            printf("statistics of %s computer's company :\n",company_name);
            printf("\n");
            printf("year : %d\n",st.year);
            printf("\n");
            printf("Exp : %d\n",Exp);
            printf("\n");
            printf("your company budget : %ld $\n",st.money);
            printf("\n");
            printf("your company customers : %d\n",st.customer);
            printf("\n");
        }
        else if(menu_select==2)
        {
            while(1)
            {
                int computer_factory_select;//the selected section in computer factory
                int build_computer;//check if the computer is build or not ?

                printf("**********************************************************\n");
                printf("\n");
                printf("Welcome to the Computers Factory !\n");
                printf("\n");

                printf("1- Build your Computer\n");
                printf("2- Hold a computer introduction event\n");
                printf("3- Exit\n");
                printf("\n");
                printf("Select a section : ");
                scanf("%d",&computer_factory_select);
                printf("\n");

                if(computer_factory_select==3)
                {
                    break;
                }
                else if(computer_factory_select==1)
                {
                    printf("**********************************************************\n");
                    printf("\n");
                    printf("Welcome to the Build your computer section !\n");
                    printf("\n");

                    if(cp[i].computer_case!=0&&cp[i].mother_board!=0&&cp[i].cpu!=0&&cp[i].ram!=0&&cp[i].graphic_card!=0&&cp[i].hard_drive!=0&&cp[i].cd_rom!=0&&cp[i].monitor!=0)
                    {
                        if(build_computer==0)
                        {
                            int build_select = 0;

                            printf("Now you can build your computer! are you sure ? 1 for yes or 2 for no : ");
                            scanf("%d",&build_select);
                            printf("\n");

                            if(build_select==2)
                            {
                                build_computer=0;
                                printf("\n");
                            }
                            else if(build_select==1)
                            {

                                build_computer=1;
                                int price_computer=price(st.year,cp[i].computer_case)+price(st.year,cp[i].mother_board)+price(st.year,cp[i].cpu)+price(st.year,cp[i].ram)+price(st.year,cp[i].graphic_card)+price(st.year,cp[i].hard_drive)+price(st.year,cp[i].cd_rom)+price(st.year,cp[i].monitor);
                                int profit_build=(price_computer*5)/100;
                                computer_price=price_computer+profit_build;
                                profit=profit_build;
                                printf("Congratulations ! your computer is built\n");
                                printf("\n");
                                printf("Now Enter a name for your computer : ");
                                scanf("%s",&cp[i].name);
                                printf("\n");

                                printf("**********************************************************\n");
                                printf("\n");
                                printf("The price of %s computer is equal to %d $ \n",cp[i].name,price_computer);
                                printf("\n");
                                printf("And your profit from the sale of each computer is equal to %d $\n",profit);
                                printf("\n");
                                Exp+=profit/10;
                                printf("%d Exp received\n",profit/10);
                                printf("\n");

                            }

                        }
                        else
                        {
                            printf("sorry you must first create an event for your computer\n");
                            printf("\n");
                        }

                    }
                    else
                    {

                        if(cp[i].computer_case==0)
                        {
                            printf("you must first buy a case for your computer\n");
                            printf("\n");

                        }
                        else if(cp[i].mother_board==0)
                        {
                            printf("you must first buy a mother board for your computer\n");
                            printf("\n");
                        }
                        if(cp[i].cpu==0)
                        {
                            printf("you must first buy a cpu for your computer\n");
                            printf("\n");
                        }
                        if(cp[i].ram==0)
                        {
                            printf("you must first buy a ram for your computer\n");
                            printf("\n");
                        }
                        if(cp[i].graphic_card==0)
                        {
                            printf("you must first buy a graphic card for your computer\n");
                            printf("\n");
                        }
                        if(cp[i].hard_drive==0)
                        {
                            printf("you must first buy hard drive for your computer\n");
                            printf("\n");
                        }
                        if(cp[i].cd_rom==0)
                        {
                            printf("you must first buy a cd rom for your computer\n");
                            printf("\n");
                        }
                        if(cp[i].monitor==0)
                        {
                            printf("you must first buy a monitor for your computer\n");
                            printf("\n");
                        }


                    }
                }
                else if(computer_factory_select==2)
                {
                    if(build_computer==1)
                    {
                        printf("the %s computer was able to rank well in the world computer sale chart\n",cp[i].name);
                        printf("\n");
                        printf("This new product from %s company will be available for %d $\n",company_name,computer_price);
                        printf("\n");
                        printf("The final profit of this product for %s company will be equal to %d $\n",company_name,(profit)*st.customer);
                        printf("\n");
                        st.money+=(profit*st.customer)+computer_price;
                        cp[i].price=computer_price;
                        cp[i].profit=profit*st.customer;
                        st.customer+=10;
                        i++;
                        build_computer=0;
                    }
                    else
                    {
                        printf("you must first build a computer\n");
                        printf("\n");
                    }

                }

            }
        }
        else if(menu_select==3)
        {
            while(1)
            {
                printf("**********************************************************\n");
                printf("\n");
                printf("Welcome to the store !\n");
                printf("\n");

                printf("1- Computer Case\n");
                printf("2- Mother Board\n");
                printf("3- CPU\n");
                printf("4- RAM\n");
                printf("5- Graphic Card\n");
                printf("6- Hard Drive\n");
                printf("7- Cd Rom\n");
                printf("8- Monitor\n");
                printf("9- Exit\n");
                printf("\n");

                printf("Select a section : ");
                scanf("%d",&store_select);
                printf("\n");

                if(store_select==1)
                {
                    int case_select =0;//the selected case
                    int answer=0;

                    printf("**********************************************************\n");
                    printf("\n");
                    printf("1- Mini Tower case : %d $\n",price(st.year,1));
                    printf("2- Mid Tower case : %d $\n",price(st.year,2));
                    printf("3- SFF Tower case : %d $\n",price(st.year,3));
                    printf("4- HTPC case : %d $\n",price(st.year,4));
                    printf("5- Full Tower case : %d $\n",price(st.year,5));
                    printf("6- Exit \n");
                    printf("\n");

                    printf("Select a section : ");
                    scanf("%d",&case_select);
                    printf("\n");
                    if(case_select==6)
                    {
                        printf("\n");
                    }
                    else if(case_select==1||case_select==2||case_select==3||case_select==4||case_select==5)
                    {
                        if(cp[i].computer_case==0)//check for parts in store
                        {

                            printf("are you sure to buy that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");


                            if(answer==1)
                            {
                                cp[i].computer_case=case_select;
                                switch (case_select)
                                {
                                    case 1:
                                    {
                                        if(st.money>=price(st.year,1))
                                        {
                                            st.money=st.money-price(st.year,1);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].computer_case=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }

                                    }
                                    case 2:
                                    {
                                        if(st.money>=price(st.year,2))
                                        {
                                            st.money=st.money-price(st.year,2);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].computer_case=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 3:
                                    {
                                        if(st.money>=price(st.year,3))
                                        {
                                            st.money=st.money-price(st.year,3);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].computer_case=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 4:
                                    {
                                        if(st.money>=price(st.year,4))
                                        {
                                            st.money=st.money-price(st.year,4);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].computer_case=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 5:
                                    {
                                        if(st.money>=price(st.year,5))
                                        {
                                            st.money=st.money-price(st.year,5);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].computer_case=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }

                                    }
                                }
                            }
                            else if(answer==2)
                            {
                                printf("ok you can buy another part !\n");
                                printf("\n");
                            }


                        }
                        else
                        {
                            printf("you have already purchased this part !\n");
                            printf("\n");
                        }



                    }
                    else
                    {
                        printf("please enter a valid section \n");
                        printf("\n");
                    }

                }
                else if(store_select==2)
                {
                    int motherboard_select =0;//the selected mother board
                    int answer=0;

                    printf("**********************************************************\n");
                    printf("\n");
                    printf("1- Mini ITX Mother Board : %d $\n",price(st.year,1));
                    printf("2- Micro ATX Mother Board : %d $\n",price(st.year,2));
                    printf("3- Standard ATX Mother Board : %d $\n",price(st.year,3));
                    printf("4- Extended ATX Mother Board : %d $\n",price(st.year,4));
                    printf("5- Exit \n");
                    printf("\n");

                    printf("Select a section : ");
                    scanf("%d",&motherboard_select);
                    printf("\n");

                    if(motherboard_select==5)
                    {
                        printf("\n");
                    }
                    else if(motherboard_select==1||motherboard_select==2||motherboard_select==3||motherboard_select==4)
                    {
                        if(cp[i].mother_board==0)//check for parts in store
                        {

                            printf("are you sure to buy that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");


                            if(answer==1)
                            {
                                cp[i].mother_board=motherboard_select;
                                switch (motherboard_select)
                                {
                                    case 1:
                                    {
                                        if(st.money>=price(st.year,1))
                                        {
                                            st.money=st.money-price(st.year,1);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].mother_board=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 2:
                                    {
                                        if(st.money>=price(st.year,2))
                                        {
                                            st.money=st.money-price(st.year,2);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].mother_board=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 3:
                                    {
                                        if(st.money>=price(st.year,3))
                                        {
                                            st.money=st.money-price(st.year,3);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].mother_board=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 4:
                                    {
                                        if(st.money>=price(st.year,4))
                                        {
                                            st.money=st.money-price(st.year,4);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].mother_board=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }

                                }
                            }
                            else if(answer==2)
                            {
                                printf("ok you can buy another part !\n");
                                printf("\n");
                            }


                        }
                        else
                        {
                            printf("you have already purchased this part !\n");
                            printf("\n");
                        }


                    }
                    else
                    {
                        printf("please enter a valid section\n");
                        printf("\n");
                    }

                }
                else if(store_select==3)
                {
                    int cpu_select =0;//the selected cpu
                    int answer=0;

                    printf("**********************************************************\n");
                    printf("\n");
                    printf("1- intel Celeron Cpu : %d $\n",price(st.year,1));
                    printf("2- intel pentium Cpu : %d $\n",price(st.year,2));
                    printf("3- intel Core i3 Cpu : %d $\n",price(st.year,3));
                    printf("4- intel Core i5 Cpu : %d $\n",price(st.year,4));
                    printf("5- intel Core i7 Cpu : %d $\n",price(st.year,5));
                    printf("6- intel Core i9 Cpu : %d $\n",price(st.year,6));
                    printf("7- Exit \n");
                    printf("\n");

                    printf("Select a section : ");
                    scanf("%d",&cpu_select);
                    printf("\n");

                    if(cpu_select==7)
                    {
                        printf("\n");
                    }
                    else if(cpu_select==1||cpu_select==2||cpu_select==3||cpu_select==4||cpu_select==5||cpu_select==6)
                    {
                        if(cp[i].cpu==0)//check for parts in store
                        {

                            printf("are you sure to buy that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");


                            if(answer==1)
                            {
                                cp[i].cpu=cpu_select;
                                switch (cpu_select)
                                {
                                    case 1:
                                    {
                                        if(st.money>=price(st.year,1))
                                        {
                                            st.money=st.money-price(st.year,1);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].cpu=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 2:
                                    {
                                        if(st.money>=price(st.year,2))
                                        {
                                            st.money=st.money-price(st.year,2);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].cpu=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 3:
                                    {
                                        if(st.money>=price(st.year,3))
                                        {
                                            st.money=st.money-price(st.year,3);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].cpu=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 4:
                                    {
                                        if(st.money>=price(st.year,4))
                                        {
                                            st.money=st.money-price(st.year,4);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].cpu=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 5:
                                    {
                                        if(st.money>=price(st.year,5))
                                        {
                                            st.money=st.money-price(st.year,5);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].cpu=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 6:
                                    {
                                        if(st.money>=price(st.year,6))
                                        {
                                            st.money=st.money-price(st.year,6);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].cpu=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }

                                }
                            }
                            else if(answer==2)
                            {
                                printf("ok you can buy another part !\n");
                                printf("\n");
                            }


                        }
                        else
                        {
                            printf("you have already purchased this part !\n");
                            printf("\n");
                        }


                    }
                    else
                    {
                        printf("please enter a valid section\n");
                        printf("\n");
                    }

                }
                else if(store_select==4)
                {
                    int ram_select =0;//the selected RAM
                    int answer=0;

                    printf("**********************************************************\n");
                    printf("\n");
                    printf("1- SDRAM : %d $\n",price(st.year,1));
                    printf("2- DDR SDRAM : %d $\n",price(st.year,2));
                    printf("3- GDDR SDRAM : %d $\n",price(st.year,3));
                    printf("4- Exit \n");
                    printf("\n");

                    printf("Select a section : ");
                    scanf("%d",&ram_select);
                    printf("\n");

                    if(ram_select==4)
                    {
                        printf("\n");
                    }
                    else if(ram_select==1||ram_select==2||ram_select==3)
                    {
                        if(cp[i].ram==0)//check for parts in store
                        {

                            printf("are you sure to buy that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");


                            if(answer==1)
                            {
                                cp[i].ram=ram_select;
                                switch (ram_select)
                                {
                                    case 1:
                                    {
                                        if(st.money>=price(st.year,1))
                                        {
                                            st.money=st.money-price(st.year,1);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].ram=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 2:
                                    {
                                        if(st.money>=price(st.year,2))
                                        {
                                            st.money=st.money-price(st.year,2);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].ram=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 3:
                                    {
                                        if(st.money>=price(st.year,3))
                                        {
                                            st.money=st.money-price(st.year,3);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].ram=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }

                                }
                            }
                            else if(answer==2)
                            {
                                printf("ok you can buy another part !\n");
                                printf("\n");
                            }


                        }
                        else
                        {
                            printf("you have already purchased this part !\n");
                            printf("\n");
                        }


                    }
                    else
                    {
                        printf("please enter a valid section\n");
                        printf("\n");
                    }
                }
                else if(store_select==5)
                {
                    int graphic_card_select =0;//the selected graphic card
                    int answer=0;

                    printf("**********************************************************\n");
                    printf("\n");
                    printf("1- Integrated Graphic Card : %d $\n",price(st.year,1));
                    printf("2- Discrete Graphic Card : %d $\n",price(st.year,2));
                    printf("3- External Graphic Card : %d $\n",price(st.year,3));
                    printf("4- Exit \n");
                    printf("\n");

                    printf("Select a section : ");
                    scanf("%d",&graphic_card_select);
                    printf("\n");

                    if(graphic_card_select==4)
                    {
                        printf("\n");
                    }
                    else if(graphic_card_select==1||graphic_card_select==2||graphic_card_select==3)
                    {
                        if(cp[i].graphic_card==0)//check for parts in store
                        {

                            printf("are you sure to buy that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");


                            if(answer==1)
                            {
                                cp[i].graphic_card=graphic_card_select;
                                switch (graphic_card_select)
                                {
                                    case 1:
                                    {
                                        if(st.money>=price(st.year,1))
                                        {
                                            st.money=st.money-price(st.year,1);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].graphic_card=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 2:
                                    {
                                        if(st.money>=price(st.year,2))
                                        {
                                            st.money=st.money-price(st.year,2);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].graphic_card=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 3:
                                    {
                                        if(st.money>=price(st.year,3))
                                        {
                                            st.money=st.money-price(st.year,3);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].graphic_card=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }

                                }
                            }
                            else if(answer==2)
                            {
                                printf("ok you can buy another part !\n");
                                printf("\n");
                            }


                        }
                        else
                        {
                            printf("you have already purchased this part !\n");
                            printf("\n");
                        }


                    }
                    else
                    {
                        printf("please enter a valid section\n");
                        printf("\n");
                    }
                }
                else if(store_select==6)
                {
                    int hard_drive_select =0;//the selected hard drive
                    int answer=0;

                    printf("**********************************************************\n");
                    printf("\n");
                    printf("1- Floppy Drives: %d $\n",price(st.year,1));
                    printf("2- Bernoulli Drive : %d $\n",price(st.year,2));
                    printf("3- Mechanical Hard Disk Drive (HDD) : %d $\n",price(st.year,3));
                    printf("4- Solid State Drive (SSD) : %d $\n",price(st.year,4));
                    printf("5- Exit \n");
                    printf("\n");

                    printf("Select a section : ");
                    scanf("%d",&hard_drive_select);
                    printf("\n");

                    if(hard_drive_select==5)
                    {
                        printf("\n");
                    }
                    else if(hard_drive_select==1||hard_drive_select==2||hard_drive_select==3||hard_drive_select==4)
                    {
                        if(cp[i].hard_drive==0)//check for parts in store
                        {

                            printf("are you sure to buy that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");


                            if(answer==1)
                            {
                                cp[i].hard_drive=hard_drive_select;
                                switch (hard_drive_select)
                                {
                                    case 1:
                                    {
                                        if(st.money>=price(st.year,1))
                                        {
                                            st.money=st.money-price(st.year,1);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].hard_drive=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 2:
                                    {
                                        if(st.money>=price(st.year,2))
                                        {
                                            st.money=st.money-price(st.year,2);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].hard_drive=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 3:
                                    {
                                        if(st.money>=price(st.year,3))
                                        {
                                            st.money=st.money-price(st.year,3);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].hard_drive=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 4:
                                    {
                                        if(st.money>=price(st.year,4))
                                        {
                                            st.money=st.money-price(st.year,4);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].hard_drive=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }

                                }
                            }
                            else if(answer==2)
                            {
                                printf("ok you can buy another part !\n");
                                printf("\n");
                            }


                        }
                        else
                        {
                            printf("you have already purchased this part !\n");
                            printf("\n");
                        }


                    }
                    else
                    {
                        printf("please enter a valid section \n");
                        printf("\n");
                    }
                }
                else if(store_select==7)
                {
                    int cd_rom_select =0;//the selected hard drive
                    int answer=0;

                    printf("**********************************************************\n");
                    printf("\n");
                    printf("1- Internal CD Rom %d $\n",price(st.year,1));
                    printf("2- External CD Rom : %d $\n",price(st.year,2));
                    printf("3- Exit \n");
                    printf("\n");

                    printf("Select a section : ");
                    scanf("%d",&cd_rom_select);
                    printf("\n");

                    if(cd_rom_select==3)
                    {
                        printf("\n");
                    }
                    else if(cd_rom_select==1||cd_rom_select==2)
                    {
                        if(cp[i].cd_rom==0)//check for parts in store
                        {

                            printf("are you sure to buy that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");


                            if(answer==1)
                            {
                                cp[i].cd_rom=cd_rom_select;
                                switch (cd_rom_select)
                                {
                                    case 1:
                                    {
                                        if(st.money>=price(st.year,1))
                                        {
                                            st.money=st.money-price(st.year,1);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].cd_rom=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 2:
                                    {
                                        if(st.money>=price(st.year,2))
                                        {
                                            st.money=st.money-price(st.year,2);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].cd_rom=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }

                                }
                            }
                            else if(answer==2)
                            {
                                printf("ok you can buy another part !\n");
                                printf("\n");
                            }


                        }
                        else
                        {
                            printf("you have already purchased this part !\n");
                            printf("\n");
                        }


                    }
                    else
                    {
                        printf("please enter a section \n");
                        printf("\n");
                    }
                }
                else if(store_select==8)
                {
                    int monitor_select =0;//the selected monitor
                    int answer=0;

                    printf("**********************************************************\n");
                    printf("\n");
                    printf("1- CRT Monitor: %d $\n",price(st.year,1));
                    printf("2- LCD Monitor : %d $\n",price(st.year,2));
                    printf("3- LED Monitor : %d $\n",price(st.year,3));
                    printf("4- Exit \n");
                    printf("\n");

                    printf("Select a section : ");
                    scanf("%d",&monitor_select);
                    printf("\n");

                    if(monitor_select==4)
                    {
                        printf("\n");
                    }
                    else if(monitor_select==1||monitor_select==2||monitor_select==3)
                    {
                        if(cp[i].monitor==0)//check for parts in store
                        {

                            printf("are you sure to buy that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");


                            if(answer==1)
                            {
                                cp[i].monitor=monitor_select;
                                switch (monitor_select)
                                {
                                    case 1:
                                    {
                                        if(st.money>=price(st.year,1))
                                        {
                                            st.money=st.money-price(st.year,1);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].monitor=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 2:
                                    {
                                        if(st.money>=price(st.year,2))
                                        {
                                            st.money=st.money-price(st.year,2);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].monitor=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }
                                    case 3:
                                    {
                                        if(st.money>=price(st.year,3))
                                        {
                                            st.money=st.money-price(st.year,3);
                                            printf("Thanks for your purchase!\n");
                                            printf("\n");
                                            break;

                                        }
                                        else
                                        {
                                            cp[i].monitor=0;
                                            printf("sorry you need more money to buy this product\n");
                                            printf("\n");
                                            break;

                                        }
                                    }

                                }
                            }
                            else if(answer==2)
                            {
                                printf("ok you can buy another part !\n");
                                printf("\n");
                            }


                        }
                        else
                        {
                            printf("you have already purchased this part !\n");
                            printf("\n");
                        }


                    }
                    else
                    {
                        printf("please enter a valid section \n");
                        printf("\n");
                    }
                }
                else if(store_select==9)
                {
                    printf("\n");
                    break;
                }
            }

        }
        else if(menu_select==4)
        {
            printf("**********************************************************\n");
            printf("\n");
            printf("   name of PC            price            profit\n");
            printf("\n");
            for(int j=0;j<i;j++)
            {
                printf("%s computer       price : %d $       profit : %d $\n",cp[j].name,cp[j].price,cp[j].profit);
                printf("\n");
            }
        }
        else if(menu_select==5)
        {
            while(1)
            {
                int hardware_select=0;
                int answer=0;

                printf("**********************************************************\n");
                printf("\n");
                printf("Welcome to the hardware sales section\n");
                printf("\n");

                printf("1- Computer Case\n");
                printf("2- Mother Board\n");
                printf("3- CPU\n");
                printf("4- RAM\n");
                printf("5- Graphic Card\n");
                printf("6- Hard Drive\n");
                printf("7- Cd Rom\n");
                printf("8- Monitor\n");
                printf("9- Exit\n");
                printf("\n");
                printf("Select a section : ");
                scanf("%d",&hardware_select);
                printf("\n");

                if(hardware_select==9)
                {
                    break;
                }
                else if(hardware_select==1)
                {
                    if(cp[i].computer_case!=0)
                    {
                            printf("are you sure to sell that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");
                            if(answer==1)
                            {
                                st.money+=price(st.year,cp[i].computer_case);
                                cp[i].computer_case=0;
                                printf("the money was transferred to the company account\n");
                                printf("\n");

                            }
                            else
                            {
                                printf("\n");
                            }
                    }
                    else
                    {
                        printf("you must first buy a part to be able to sell it\n");
                        printf("\n");
                    }
                }
                else if(hardware_select==2)
                {
                    if(cp[i].mother_board!=0)
                    {
                            printf("are you sure to sell that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");
                            if(answer==1)
                            {
                                st.money+=price(st.year,cp[i].mother_board);
                                cp[i].mother_board=0;
                                printf("the money was transferred to the company account\n");
                                printf("\n");

                            }
                            else
                            {
                                printf("\n");
                            }
                    }
                    else
                    {
                        printf("you must first buy a part to be able to sell it\n");
                        printf("\n");
                    }
                }
                else if(hardware_select==3)
                {
                    if(cp[i].cpu!=0)
                    {
                            printf("are you sure to sell that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");
                            if(answer==1)
                            {
                                st.money+=price(st.year,cp[i].cpu);
                                cp[i].cpu=0;
                                printf("the money was transferred to the company account\n");
                                printf("\n");

                            }
                            else
                            {
                                printf("\n");
                            }
                    }
                    else
                    {
                        printf("you must first buy a part to be able to sell it\n");
                        printf("\n");
                    }
                }
                else if(hardware_select==4)
                {
                    if(cp[i].ram!=0)
                    {
                            printf("are you sure to sell that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");
                            if(answer==1)
                            {
                                st.money+=price(st.year,cp[i].ram);
                                cp[i].ram=0;
                                printf("the money was transferred to the company account\n");
                                printf("\n");

                            }
                            else
                            {
                                printf("\n");
                            }
                    }
                    else
                    {
                        printf("you must first buy a part to be able to sell it\n");
                        printf("\n");
                    }
                }
                else if(hardware_select==5)
                {
                    if(cp[i].graphic_card!=0)
                    {
                            printf("are you sure to sell that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");
                            if(answer==1)
                            {
                                st.money+=price(st.year,cp[i].graphic_card);
                                cp[i].graphic_card=0;
                                printf("the money was transferred to the company account\n");
                                printf("\n");

                            }
                            else
                            {
                                printf("\n");
                            }
                    }
                    else
                    {
                        printf("you must first buy a part to be able to sell it\n");
                        printf("\n");
                    }
                }
                else if(hardware_select==6)
                {
                    if(cp[i].hard_drive!=0)
                    {
                            printf("are you sure to sell that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");
                            if(answer==1)
                            {
                                st.money+=price(st.year,cp[i].hard_drive);
                                cp[i].hard_drive=0;
                                printf("the money was transferred to the company account\n");
                                printf("\n");

                            }
                            else
                            {
                                printf("\n");
                            }
                    }
                    else
                    {
                        printf("you must first buy a part to be able to sell it\n");
                        printf("\n");
                    }
                }
                else if(hardware_select==7)
                {
                    if(cp[i].cd_rom!=0)
                    {
                            printf("are you sure to sell that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");
                            if(answer==1)
                            {
                                st.money+=price(st.year,cp[i].cd_rom);
                                cp[i].cd_rom=0;
                                printf("the money was transferred to the company account\n");
                                printf("\n");

                            }
                            else
                            {
                                printf("\n");
                            }
                    }
                    else
                    {
                        printf("you must first buy a part to be able to sell it\n");
                        printf("\n");
                    }
                }
                else if(hardware_select==8)
                {
                    if(cp[i].monitor!=0)
                    {
                            printf("are you sure to sell that ? Enter 1 for yes or 2 for no : ");
                            scanf("%d",&answer);
                            printf("\n");
                            if(answer==1)
                            {
                                st.money+=price(st.year,cp[i].monitor);
                                cp[i].monitor=0;
                                printf("the money was transferred to the company account\n");
                                printf("\n");

                            }
                            else
                            {
                                printf("\n");
                            }
                    }
                    else
                    {
                        printf("you must first buy a part to be able to sell it\n");
                        printf("\n");
                    }
                }
            }

        }
        else if(menu_select==6)
        {
            guide();
        }
        else if(menu_select==7)
        {
            printf("**********************************************************\n");
            break;
        }
        else
        {
            printf("please enter a valid section\n");
            printf("\n");
        }

    }

}
void guide(void)//the guide function
{
    printf("**********************************************************\n");
    printf("\n");
    printf("The guides of computer's company tycoon:\n");
    printf("\n");
    printf("1- open the store section\n");
    printf("2- buy the parts of computer that you need\n");
    printf("3- open the computer's factory section\n");
    printf("4- select build your computer option\n");
    printf("5- congratulations ! you are build your First computer!\n");
    printf("6- Enter the name for your computer \n");
    printf("7- select Hold a computer introduction event option\n");
    printf("8- finish!");
    printf("\n");
}
int price(int year,int p)
{
    int result = year *50;

    if(p==1)
    {
        return result;
    }
    else
        return result+price(year,p-1);

}

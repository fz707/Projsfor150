#ifndef _HISTORY_TRANSACTION_CPP_
#define _HISTORY_TRANSACTION_CPP_

#include <cassert>
#include <iomanip>
#include <iostream>

#include "project4.hpp"
#include "History.hpp"
#include "Transaction.hpp"

////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////
//
//

// Constructor
// TASK 1
//
Transaction::Transaction( std::string ticker_symbol,  unsigned int day_date,unsigned int month_date,  unsigned year_date,
bool buy_sell_trans,  unsigned int number_shares,double trans_amount)
{
    symbol=ticker_symbol;
    trans_id=assigned_trans_id;
    assigned_trans_id++;
    day=day_date;
    month=month_date;
    year=year_date;
    acb=0;
    if( buy_sell_trans==true){
        trans_type="Buy";
        
    }
    else{
        trans_type="Sell";
    }
    
    shares=number_shares;
    amount=trans_amount;
    acb_per_share=0;
    share_balance=0;
    cgl=0;
    p_next=nullptr;
}



// Destructor
// TASK 1
//
Transaction::~Transaction(){
}

// Overloaded < operator.
// TASK 2
//

bool Transaction::operator<( Transaction const &other)
{
    //for the if statement if my first transaction is less than my second transaction
    //this:first
    //othersecond
   
    if(this->year<other.year)
    {
    return true;
    }
    else if(this->year>other.year){
            return false;
    }
    else{
        if(this->month<other.month)
        {
        return true;
        }
        else if(this->month>other.month){
                return false;
        }
            else{
                if(this->day<other.day)
                {
                return true;
                }
                else if (this->day>other.day){
                        return false;
                }
                else{
                    return false;
                }
                }
        }
}
// GIVEN
// Member functions to get values.
//
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true: false ; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next;}

// GIVEN
// Member functions to set values.
//
void Transaction::set_acb( double acb_value ) { acb = acb_value; }
void Transaction::set_acb_per_share( double acb_share_value ) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance( unsigned int bal ) { share_balance = bal ; }
void Transaction::set_cgl( double value ) { cgl = value; }
void Transaction::set_next( Transaction *p_new_next ) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
//
void Transaction::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " "
    << std::setw(4) << get_symbol() << " "
    << std::setw(4) << get_day() << " "
    << std::setw(4) << get_month() << " "
    << std::setw(4) << get_year() << " ";


  if ( get_trans_type() ) {
    std::cout << "  Buy  ";
  } else { std::cout << "  Sell "; }

  std::cout << std::setw(4) << get_shares() << " "
    << std::setw(10) << get_amount() << " "
    << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
    << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
    << std::setw(10) << std::setprecision(3) << get_cgl()
    << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////
//
//


// Constructor
// TASK 3
//
History::History()
{
    p_head=nullptr;
}

// Destructor
// TASK 3
//
History::~History(){
    Transaction *p_temp{};
   
    while(p_head!= nullptr){
        p_temp=p_head;
         p_head=p_head->get_next();
   
        delete p_temp;
        p_temp=nullptr;
         
    }
}

// read_transaction(...): Read the transaction history from file.
// TASK 4
//
void History::read_history(){
    ece150::open_file();
    while (ece150::next_trans_entry()==true) {
        Transaction *newinput= new Transaction(
            ece150::get_trans_symbol(),
            ece150::get_trans_day(),
            ece150::get_trans_month(),
            ece150::get_trans_year(),
            ece150::get_trans_type(),
            ece150::get_trans_shares(),
            ece150::get_trans_amount());
        History::insert(newinput);
        }
    
    ece150::close_file();
}
// insert(...): Insert transaction into linked list.
// TASK 5
//
// Insert transaction in linked list.
//
void History::insert(Transaction *p_new_trans){
    if( p_head==NULL){
        p_head=p_new_trans;
    }
    else{
        Transaction *p_temp=p_head;
        while(p_temp->get_next()!= NULL){
            p_temp=p_temp->get_next();
        }
        p_temp->set_next(p_new_trans);
    }
}

// sort_by_date(): Sort the linked list by trade date.
// TASK 6
//
void History::sort_by_date(){
    //check for head to be null or only pointer in the list
    if( p_head==nullptr){ //empty list
        return;
    }
    if(p_head->get_next()==nullptr){ //checks for the p_next is nullptr -> only node in list
        return;
    }
    else{ //start insert sort
        Transaction *p_sorted=nullptr;
        Transaction *p_temp1=nullptr;
        Transaction *p_temp2=nullptr;
        p_sorted=p_head;
        p_head=p_head->get_next(); //head node becomes the next node
        p_sorted->set_next(nullptr);
                                        // detaches the temporary node
        //start p_sorted
        //start the list
        //start the while loop for step 4-5
     //   std::cout<< "made it to insertion sort" <<std::endl;
        
        while(p_head!=nullptr){
          //  std::cout<< "in the p_head!=nullptr loop" <<std::endl;
            p_temp1=p_head;
            p_head=p_head->get_next();
            //test case 1
            if(*p_temp1<*p_sorted){ //compares node to p_sorted to see if less than so front
             //   std::cout <<"in this statement" << std::endl;
                p_temp1->set_next(p_sorted);
                p_sorted=p_temp1; //moves p_sorted
                
            }
            else{
                p_temp2=p_sorted; //now assign p_temp2
             //   std::cout<< "made it to the else" <<std::endl;
                while ((p_temp2->get_next() != nullptr) && (p_temp2 != nullptr) && !(*p_temp1 < *(p_temp2->get_next()))){
                    //std::cout<< "made it in second loop" <<std::endl;
                        p_temp2=p_temp2->get_next();
                    }
                
                p_temp1->set_next(p_temp2->get_next());
                p_temp2->set_next(p_temp1); //sort the function
            }
                
            }
        
     //   std::cout<< "made it all the way out" <<std::endl;
            
        p_head=p_sorted;
    }
  
}

// update_acb_cgl(): Updates the ACB and CGL values.
// TASK 7
//

void History::update_acb_cgl(){
    // ACB on a date= ACB previous date - shares amount on the date* ACB/Share previous date
    //CGL on a date= Amount paid on that date-(shares amount sold*ACB/Share previous date)
    Transaction* iterator{};
    iterator=p_head;
    double iacb;
    iacb=p_head->get_amount(); //gets initial amount
    p_head->set_acb(iacb); //sets intial amount to acb
    unsigned int ishares; //initial shares
    ishares=p_head->get_shares(); //gets shares
    p_head->set_share_balance(ishares); //sets share balance to initial
    p_head->set_acb_per_share(iacb/ishares); //sets
    unsigned int previousshares;
    unsigned int sharebalance;
    unsigned int shares;
    double cgl;
    double acb;
    double acbforshare;
    previousshares=iterator->get_shares();
    shares=iterator->get_shares();
    acb=iterator->get_acb();
    sharebalance=iterator->get_shares();
    acbforshare=(iterator->get_acb())/(iterator->get_shares());
    double prevacbpers;
    prevacbpers=iterator->get_acb_per_share();
    double prevacb;
    prevacb=iterator->get_acb();
    double amounts;
    iterator=iterator->get_next();
   while(iterator!=nullptr){
       if(iterator->get_trans_type()==true){
           amounts=iterator->get_amount();
           acb+=amounts;
           iterator->set_acb(acb);
           shares=iterator->get_shares();
           sharebalance+=shares;
           iterator->set_share_balance(sharebalance);
           iterator->set_acb_per_share(acb/sharebalance);
           cgl=0;
           iterator->set_cgl(cgl);
           
       }
       else{ //trans type == false-- sell
           amounts=iterator->get_amount();
           shares=iterator->get_shares();
           acb=prevacb-(shares*prevacbpers);
           iterator->set_acb(acb);
           sharebalance-=shares;
           iterator->set_share_balance(sharebalance);
           iterator->set_acb_per_share(acb/sharebalance);
           cgl=amounts-(shares*prevacbpers);
           iterator->set_cgl(cgl);
       }
        //getting previous values
       prevacbpers=iterator->get_acb_per_share();
       previousshares=iterator->get_shares();
       prevacb=iterator->get_acb();
       iterator=iterator->get_next();
        
}

}

// compute_cgl(): )Compute the ACB, and CGL.
// TASK 8

double History::compute_cgl(unsigned int year){
   
    double totalcgl=0;
    double cgl;
    if(p_head==nullptr){
        return totalcgl;
    }
    Transaction *iterator{};
    iterator=p_head;
    while(iterator!=nullptr){
        if(iterator->get_year()==year){
            cgl=iterator->get_cgl();
            totalcgl+=cgl;
        }
        iterator=iterator->get_next();
    }
    return totalcgl;
}


// print() Print the transaction history.
//TASK 9
//
void History::print(){

    Transaction* printer{};
    //needs header
    printer=p_head;
    std::cout<< "========== BEGIN TRANSACTION HISTORY ============" << std::endl;
    while(printer!= nullptr){
        
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(4) << printer->get_trans_id() << " "
      << std::setw(4) << printer->get_symbol() << " "
      << std::setw(4) <<printer-> get_day() << " "
      << std::setw(4) << printer->get_month() << " "
      << std::setw(4) << printer->get_year() << " ";


    if ( printer->get_trans_type() ) {
      std::cout << "  Buy  ";
    } else { std::cout << "  Sell "; }

    std::cout << std::setw(4) << printer->get_shares() << " "
      << std::setw(10) << printer->get_amount() << " "
      << std::setw(10) << printer->get_acb() << " " << std::setw(4) << printer->get_share_balance() << " "
      << std::setw(10) << std::setprecision(3) << printer->get_acb_per_share() << " "
      << std::setw(10) << std::setprecision(3) << printer->get_cgl()
      << std::endl;
        printer=printer->get_next();
    }
    std::cout<< "========== END TRANSACTION HISTORY ============" << std::endl;
  }



// GIVEN
// get_p_head(): Full access to the linked list.
//
Transaction *History::get_p_head() { return p_head; }


#endif

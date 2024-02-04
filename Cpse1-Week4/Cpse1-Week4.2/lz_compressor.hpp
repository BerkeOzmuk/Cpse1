#ifndef LZ_COMPPRESSOR_HPP
#define LZ_COMPRESSOR_HPP

#include <array>
#include "match.hpp"


template< int N > 
class lz_compressor {
private:   
   char buffer[ N ];
   int used;
   
   template< typename F >
   void read_buffer( F read ){
      used = 0;
      for(;;){
         auto c = read();

         if( used == N ){
            std::cerr << "buffer overflow";
            break;
         }

         if( c == '@' ){
            std::cerr << "text contains @";
            break;
         }
         if( c == '\0' ){
            break;
         }

         buffer[ used++ ] = c;
      }         
   }

   template< typename F >
   void write_compressed_buffer( F write ){
      for( int i = 0; i < used; ){
         auto match = find( i );
         if( match.length > 2 ){
            write( '@' );
            write( '0' + match.offset );
            write( '0' + match.length );
            i += match.length;
         } else {
            write( buffer[ i++ ] );
         }
      }
   }

   match find( int index ){
      auto best = match( 0 );
      for( int i = std::max( 0, index - 40 ); i < index - 1; ++i ){
         auto length = std::min( 
            40, 
            count_identical_prefix_length( i, index ));
         best = std::max( best, match( index - i - 1, length ) );
      }
      return best;
   }
   
   int count_identical_prefix_length( int s, int p ){
      return ( buffer[ s ] != buffer[ p ] )
         ? 0 
         : 1 + count_identical_prefix_length( s + 1, p + 1 );
   }   
   
   
   
   
   
public: 

   template< typename S, typename D >
   void compress( S read, D write ){
      read_buffer( read );
      write_compressed_buffer( write ); 
   }
   
};

#endif
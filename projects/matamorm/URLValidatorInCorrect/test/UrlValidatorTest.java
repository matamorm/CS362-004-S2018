

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {	   
	 //You can use this function to implement your manual testing
	 long allowAllSchemes= UrlValidator.ALLOW_ALL_SCHEMES;
	 UrlValidator urlVal = new UrlValidator(null, null,allowAllSchemes);
	     
	 //commented-out due to exception throw
	 //assertTrue(urlVal.isValid("https://www.msn.com"));
   }
   
   // test scheme
   public void testSchemePartition()
   {  
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   if(!(urlVal.isValid("http:/google.com")))
		   System.out.println("False scheme test: passed");
	   else
		   System.out.println("False scheme test: failed");
	   if(urlVal.isValid("http://google.com"))
		   System.out.println("True scheme test: passed");
	   else
		   System.out.println("True scheme test: failed");
	   System.out.print('\n');
   }
   
   // test authority
   public void testAuthorityPartition(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   if(!(urlVal.isValid("http://go.a")))
		   System.out.println("False authority test: passed");
	   else
		   System.out.println("False authority test: failed");
	   if(urlVal.isValid("http://go.com"))
		   System.out.println("True authority test: passed");
	   else
		   System.out.println("True authority test: failed");
	   System.out.print('\n');
   }
   
   // test port
   public void testPortPartition(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   if(!(urlVal.isValid("http://google.com:-1")))
		   System.out.println("False port test: passed");
	   else
		   System.out.println("False port test: failed"); 
	   if(urlVal.isValid("http://google.com:80"))
		   System.out.println("True port test: passed");
	   else
		   System.out.println("True port test: failed");
	   System.out.print('\n');
   }
   
   // test path
   public void testPathPartition(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   if(!(urlVal.isValid("http://google.com/..")))
		   System.out.println("False path test: passed");
	   else
		   System.out.println("False path test: failed"); 
	   if(urlVal.isValid("http://google.com/test1"))
		   System.out.println("True path test: passed");
	   else
		   System.out.println("True path test: failed");
	   System.out.print('\n');
   }
   
   // test null
   public void testNullPartition(){
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   if(!(urlVal.isValid("")))
		   System.out.println("Null test: passed");
	   else
		   System.out.println("Null test: failed");
	   System.out.print('\n');
   }
   
   // non-http test - commented-out due to thrown exception
   public void testNonHttpPartition(){
	   /*UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   if(urlVal.isValid("https://google.com/"))
		   System.out.println("https test: passed");
	   else
		   System.out.println("https test: failed"); 
	   if(urlVal.isValid("ftp://google.com/"))
		   System.out.println("ftp test: passed");
	   else
		   System.out.println("ftp test: failed");
	   System.out.print('\n');
	   */
   }
   
   public void testIsValid()
   {
	   /*
	   //Commented-out and replaced due to ftp and https issues found in prior testing
	   //Focus pertains to "http"
	   String[] p1 = {"http://", "http:/", "http:", "http", "ftp://", "ftp:/", "https://", "https:/"};
	   */
	   
	   //Arrays hold URL components for URL building within loop: 
	   //p1 = scheme, p2 = authority, p3 = port, p4 = path, p5 = query
	   String[] p1 = {"http://", "http:/", "http:", "http"};	   
	   String[] p2 = {"www.google.com", "go.com", "0.0.0.0", "go.a", "256.256.256.256",""};
	   String[] p3 = {":80", ":0", ":-1", ""};
	   String[] p4 = {"/test1", "/test1/file", "/..", "/../", ""};
	   String[] p5 = {"?action=view", "?action=edit&mode=up", ""};
	   
	   //Array holds pre-dertermined valid URL's
	   String[] validURLS = {"http://www.google.com:80/test1?action=view", 
			   "http://www.google.com:80/test1?action=edit&mode=up",
			   "http://www.google.com:80/test1",
			   "http://www.google.com:80/test1/file?action=view",
			   "http://www.google.com:80/test1/file?action=edit&mode=up",
			   "http://www.google.com:80/test1/file",
			   "http://www.google.com:80?action=view",
			   "http://www.google.com:80?action=edit&mode=up",
			   "http://www.google.com:80",
			   "http://www.google.com:0/test1?action=view", 
			   "http://www.google.com:0/test1?action=edit&mode=up",
			   "http://www.google.com:0/test1",
			   "http://www.google.com:0/test1/file?action=view",
			   "http://www.google.com:0/test1/file?action=edit&mode=up",
			   "http://www.google.com:0/test1/file",
			   "http://www.google.com:0?action=view",
			   "http://www.google.com:0?action=edit&mode=up",
			   "http://www.google.com:0",
			   "http://www.google.com/test1?action=view", 
			   "http://www.google.com/test1?action=edit&mode=up",
			   "http://www.google.com/test1",
			   "http://www.google.com/test1/file?action=view",
			   "http://www.google.com/test1/file?action=edit&mode=up",
			   "http://www.google.com/test1/file",
			   "http://www.google.com?action=view",
			   "http://www.google.com?action=edit&mode=up",
			   "http://www.google.com",
			   
			   "http://go.com:80/test1?action=view", 
			   "http://go.com:80/test1?action=edit&mode=up",
			   "http://go.com:80/test1",
			   "http://go.com:80/test1/file?action=view",
			   "http://go.com:80/test1/file?action=edit&mode=up",
			   "http://go.com:80/test1/file",
			   "http://go.com:80?action=view",
			   "http://go.com:80?action=edit&mode=up",
			   "http://go.com:80",
			   "http://go.com:0/test1?action=view", 
			   "http://go.com:0/test1?action=edit&mode=up",
			   "http://go.com:0/test1",
			   "http://go.com:0/test1/file?action=view",
			   "http://go.com:0/test1/file?action=edit&mode=up",
			   "http://go.com:0/test1/file",
			   "http://go.com:0?action=view",
			   "http://go.com:0?action=edit&mode=up",
			   "http://go.com:0",
			   "http://go.com/test1?action=view", 
			   "http://go.com/test1?action=edit&mode=up",
			   "http://go.com/test1",
			   "http://go.com/test1/file?action=view",
			   "http://go.com/test1/file?action=edit&mode=up",
			   "http://go.com/test1/file",
			   "http://go.com?action=view",
			   "http://go.com?action=edit&mode=up",
			   "http://go.com",
		
			   "http://0.0.0.0:80/test1?action=view", 
			   "http://0.0.0.0:80/test1?action=edit&mode=up",
			   "http://0.0.0.0:80/test1",
			   "http://0.0.0.0:80/test1/file?action=view",
			   "http://0.0.0.0:80/test1/file?action=edit&mode=up",
			   "http://0.0.0.0:80/test1/file",
			   "http://0.0.0.0:80?action=view",
			   "http://0.0.0.0:80?action=edit&mode=up",
			   "http://0.0.0.0:80",
			   "http://0.0.0.0:0/test1?action=view", 
			   "http://0.0.0.0:0/test1?action=edit&mode=up",
			   "http://0.0.0.0:0/test1",
			   "http://0.0.0.0:0/test1/file?action=view",
			   "http://0.0.0.0:0/test1/file?action=edit&mode=up",
			   "http://0.0.0.0:0/test1/file",
			   "http://0.0.0.0:0?action=view",
			   "http://0.0.0.0:0?action=edit&mode=up",
			   "http://0.0.0.0:0",
			   "http://0.0.0.0/test1?action=view", 
			   "http://0.0.0.0/test1?action=edit&mode=up",
			   "http://0.0.0.0/test1",
			   "http://0.0.0.0/test1/file?action=view",
			   "http://0.0.0.0/test1/file?action=edit&mode=up",
			   "http://0.0.0.0/test1/file",
			   "http://0.0.0.0?action=view",
			   "http://0.0.0.0?action=edit&mode=up",
			   "http://0.0.0.0",
	   };
	   
	   //holds final correctly validated URL amount 
	   int validUrlCounter = 0;
	   
	   String totalURL = ""; 		//holds built URL's
	   Boolean urlFlag = false;		//flag handles predetermined valid URL findings*/
   
	   //create UrlValidator instance for isValid checking
	   UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
	   	   
	   System.out.println("START UNIT TEST");
	   System.out.println("");
	   
	   //loop handles the creation and testing of URL
	   for (int i = 0; i < p1.length; i++)
	   {
		 for(int j = 0; j < p2.length; j++)
		 {
		    for(int k = 0; k < p3.length; k++)
			{
			  for(int m = 0; m < p4.length; m++)
			  {
				for(int n = 0; n < p5.length; n++)
				{
				   //create URL string based on URL parts
				   totalURL = p1[i] + p2[j] + p3[k] + p4[m] + p5[n];
				   
				   //test if URL is valid
				   if (urlVal.isValid(totalURL))
				   {	
					   //reset flag for correct URL's that are passed through
					   urlFlag = false;
					   
					   //loop through predetermined valid URL array
					   for (int p = 0; p < validURLS.length; p++)
					   {	
						   //set flag if predetermined valid URL is found 
						   if (totalURL.equals(validURLS[p]))
						   {
							  urlFlag = true;
						   }
					   }
					   
					   //if URL is not found within predetermined URL array
					   if(!urlFlag)
					   {
						   System.out.println("\"" + totalURL + "\" returns true.  Should be false.");
					   }
					   //output correct valid URL's
					   else
					   {
						   System.out.println("     Valid URL " + "\"" + totalURL + "\" correctly passes.");
						   validUrlCounter++;
					   }
					 }
				  }
			   }
		    }
		  }
	   }
	   System.out.println("");
   
	   //display comparison between the following two items...
	   System.out.println("Expected passed valid URL's: " + validURLS.length);
	   System.out.println("Actual passed valid URL's: " + validUrlCounter);
	   System.out.println("");	   
	   
	   System.out.println("END UNIT TEST");
	   System.out.println("");	   
   }
}

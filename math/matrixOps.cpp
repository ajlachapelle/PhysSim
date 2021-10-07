// You might not need matrix operations to be separate, vectors would just be a special case of matrices
// When iterating over a vector, you'd have to be using a function that works on the individual elements (e.g. doubles) as well as recursively over another vector

//
string getMatrixString(const ?* matrix)
{
  // TODO: Allow for specifying precision; might need to have the function work with a container object instead of a standard vector
  // define a print function for elements of the vector and use recursion?
  // scientific notation? (maybe just for 10^-x, not 10^x)

  // string << vector << \n;
  for (vector<double> rowVector : matrix)
  {
    cout << "[";
    for (double component : rowVector)
    {
      cout << " " << component << " ";
    }
    cout << "]" << endl;
  }
  return ;
}

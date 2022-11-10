<a name="readme-top"></a>

<h3 align="center">Simple XOR in c</h3>

  <p align="center">
    An xor neuralnetwork made in C by an EPITA Student
    <br />

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

This simple neural network was made to create an OCR for a project for EPITA.
The purpose of our OCR is to solve sudoku grids. The goal of my neural network is to recognize numbers.
The implementation provided here allows to test my network by training it on an XOR. I did not provide the code for image recognition.

My implementation is based only on a single hidden layer.
You can adapt it and use multiple layer if you want.

<!-- GETTING STARTED -->
## Getting Started

Here is how to get a local copy of my Neural Network

### Prerequisites

* gcc

### Installation

1 Clone the repo
   ```sh
   git clone https://github.com/Toinetoine1/XOR.git
   ```
2 Compile and Run
   ```sh
   gcc -lm -o xor *.c && ./xor
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Usage

When running the executable, you will see the number of Epoch and the result of the XOR.

Here is an example of my XOR:
```
Input neurons: 2
Hidden neurons: 10
Output neurons: 1

Learning Rate: 0.100000
Epoch: 10000
Training sets: 4

Result:
0 and 0: 0.044982
0 and 1: 0.947089
1 and 0: 0.953937
1 and 1: 0.055884
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CONTRIBUTING -->
## Contributing

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Discord:Toinetoine3#5383

Email: antoine.resen@gmail.com

<p align="right">(<a href="#readme-top">back to top</a>)</p>
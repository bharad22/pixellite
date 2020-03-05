#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
char name[] = "lenaygray.bmp";
int data = 0, offset, bpp = 0, width, height;
long bmpsize = 0, bmpdataoff = 0;
int** image;
int temp = 0;


FILE* image_file;
image_file = fopen("lenagray.bmp", "rb");
if (image_file == NULL)
{
	printf("Error Opening File!!");
	exit(1);
}
else
{


	offset = 0;


	offset = 2;

	fseek(image_file, offset, SEEK_SET);

	// Getting size of BMP File
	fread(&bmpsize, 4, 1, image_file);


	offset = 10;

	fseek(image_file, offset, SEEK_SET);

	// Bitmap data offset
	fread(&bmpdataoff, 4, 1, image_file);


	fseek(image_file, 18, SEEK_SET);

	fread(&width, 4, 1, image_file);

	fread(&height, 4, 1, image_file);


	fseek(image_file, 2, SEEK_CUR);

	fread(&bpp, 2, 1, image_file);

	// Setting offset to start of pixel data
	fseek(image_file, bmpdataoff, SEEK_SET);

	// Creating Image array
	image = (int**)malloc(height * sizeof(int*));
	for (int i = 0; i < height; i++)
	{
		image[i] = (int*)malloc(width * sizeof(int));
	}


	int numbytes = (bmpsize - bmpdataoff) / 3;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			fread(&temp, 3, 1, image_file);

			temp = temp & 0x0000FF;
			image[i][j] = temp;
		}
	}
}

int arr[256];
for(int i=0;i<256;i++)
{
    arr[i]=0;
}
for(int i=0;i<height;i++)
{
    for(int j=0;j<width;j++)
    {
        arr[image[i][j]] +=1;
        cout<<arr[image[i][j]]<<endl;
    }
}

}

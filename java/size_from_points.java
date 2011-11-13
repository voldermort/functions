		//arr is an arraylist of points
		double xx=0,yy=0; 
		for(int i=0;i<arr.size()-1;i++){
		xx=xx+arr.get(i).x*arr.get(i+1).y;
		yy=yy+arr.get(i).y*arr.get(i+1).x;
		}
		xx=xx+arr.get(arr.size()-1).x*arr.get(0).y;
		yy=yy+arr.get(arr.size()-1).y*arr.get(0).x;
		System.out.println(xx/2-yy/2);

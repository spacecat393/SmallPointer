// void file_writer_modelFile(SourceDataType *sourcedatatype_ptr, const char *path)
// {
//	 if (CP_COMPRESS)
//	 {
//		 std::string main_name = "Results/" + string;
//		 FolderWriter::name(main_name);
//
//		 for (int i = 0; i < sourcedatatype.object_name_vector.size(); ++i)
//		 {
//			 std::string name = main_name + sourcedatatype.object_name_vector[i];
//			 FolderWriter::name(name);
//
//			 FileWriter::intPack(sourcedatatype.unpack_index[i], name + sourcedatatype.index_name);
//			 FileWriter::floatPack(sourcedatatype.pack_positions[i], name + sourcedatatype.vertices_name);
//			 FileWriter::floatPack(sourcedatatype.pack_normals[i], name + sourcedatatype.normals_name);
//			 FileWriter::floatPack(sourcedatatype.pack_texcoord[i], name + sourcedatatype.texcoord_name);
//
//			 if (SourceDataType::CREATE_COLOR)
//			 {
//				 FileWriter::floatPack(sourcedatatype.pack_color[i], name + sourcedatatype.color_name);
//			 }
//
//			 if (sourcedatatype.create_animation)
//			 {
//				 // FileWriter::stringPack(sourcedatatype.joints[i], name + sourcedatatype.jointsidentity_name);
//				 // FileWriter::floatPack(sourcedatatype.un_pack_visual_bones[i], name + sourcedatatype.visualbones_name);
//				 // FileWriter::unPackBones(sourcedatatype, name + sourcedatatype.bones_name, i);
//				 // FileWriter::unPackBonesM4x4(sourcedatatype, name + sourcedatatype.bones_m4x4_name, i);
//
//				 // FileWriter::floatPack(sourcedatatype.bind_poses[i], name + sourcedatatype.bindposes_name);
//				 FileWriter::intPack(sourcedatatype.pack_joints[i], name + sourcedatatype.joints_name);
//				 FileWriter::floatPack(sourcedatatype.pack_weights[i], name + sourcedatatype.weights_name);
//
//				 // std::string animation_name = name + sourcedatatype.animation_name;
//				 // FolderWriter::name(animation_name);
//
//				 // FileWriter::intPack(sourcedatatype.skinning_bones[i], animation_name + sourcedatatype.skinning_bones_name);
//				 // FileWriter::intPack(sourcedatatype.animation_bones[i], animation_name + sourcedatatype.animation_bones_name);
//			 }
//		 }
//
//		 if (sourcedatatype.create_animation)
//		 {
//			 std::string name = main_name + sourcedatatype.animation_name;
//			 FolderWriter::name(name);
//
//			 // FileWriter::floatPack(sourcedatatype.un_pack_visual_bones[0], name + sourcedatatype.visualbones_name);
//			 FileWriter::unPackBones(sourcedatatype, name + sourcedatatype.bones_name, 0);
//			 FileWriter::floatPack(sourcedatatype.bind_poses[0], name + sourcedatatype.bindposes_name);
//
//			 FileWriter::floatPack(sourcedatatype.armature_transform_vector, name + sourcedatatype.transforms_name);
//			 FileWriter::stringPack(sourcedatatype.armature_string_vector, name + sourcedatatype.jointsidentity_name);
//			 // FileWriter::floatPack(sourcedatatype.armature_time_vector, name + sourcedatatype.times_name);
//		 }
//	 }
//	 else
//	 {
//
//	 }
// }
//
// void FileWriter::floatPack(std::vector<float>& float_vector, const std::string& string)
// {
//	 std::ofstream file(string, std::ios::binary);
//
//	 if (file.is_open())
//	 {
//		 for (int i = 0; i < float_vector.size(); ++i)
//		 {
//			 file.write(reinterpret_cast<const char*>(&float_vector[i]), sizeof(float));
//		 }
//
//		 file.close();
//	 }
//	 else
//	 {
//		 std::printf("FileWriter %s\n", string.c_str());
//	 }
// }
//
// void FileWriter::intPack(std::vector<int>& int_vector, const std::string& string)
// {
//	 std::ofstream file(string, std::ios::binary);
//
//	 if (file.is_open())
//	 {
//		 int size = int_vector.size();
//
//		 for (int i = 0; i < size; ++i)
//		 {
//			 file.write(reinterpret_cast<const char*>(&int_vector[i]), sizeof(int));
//		 }
//
//		 file.close();
//	 }
//	 else
//	 {
//		 std::printf("FileWriter %s\n", string.c_str());
//	 }
// }
//
// void FileWriter::stringPack(std::vector<std::string>& string_vector, const std::string& string)
// {
//	 std::ofstream file(string);
//
//	 if (file.is_open())
//	 {
//		 int size = string_vector.size();
//
//		 for (int i = 0; i < size; ++i)
//		 {
//			 file << string_vector[i];
//
//			 if (i < size - 1)
//			 {
//				 file << "\n";
//			 }
//		 }
//
//		 file.close();
//	 }
//	 else
//	 {
//		 std::printf("FileWriter %s\n", string.c_str());
//	 }
// }
//
// void FileWriter::bytePack(std::vector<unsigned char>& unsigned_char_vector, const std::string& string)
// {
//	 std::ofstream file(string, std::ios::binary);
//
//	 if (file.is_open())
//	 {
//		 file.write(reinterpret_cast<const char*>(unsigned_char_vector.data()), unsigned_char_vector.size());
//
//		 file.close();
//	 }
//	 else
//	 {
//		 std::printf("FileWriter %s\n", string.c_str());
//	 }
// }
//
// void FileWriter::unPackBones(SourceDataType& sourcedatatype, const std::string& string, const int& x)
// {
//	 FolderWriter::name(string);
//
//	 std::ofstream file(string + "/" + std::to_string(0), std::ios::binary);
//
//	 for (int y = 0; y < sourcedatatype.bones_string_vector_vector_vector[x].size(); ++y)
//	 {
//		 std::vector<std::string> bones_string_vector_vector_vector;
//
//		 for (int z = 0; z < sourcedatatype.bones_string_vector_vector_vector[x][y].size(); ++z)
//		 {
//			 bones_string_vector_vector_vector.push_back("*" + sourcedatatype.bones_string_vector_vector_vector[x][y][z] + "*");
//		 }
//
//		 for (int w = 0; w < sourcedatatype.joints[x].size(); ++w)
//		 {
//			 int index = GraphicReader::matchString(sourcedatatype.joints[x][w], bones_string_vector_vector_vector, '*', '*');
//			 if (index != -1)
//			 {
//				 file.write(reinterpret_cast<const char*>(&w), sizeof(int));
//			 }
//		 }
//
//		 file.close();
//
//		 if (y < sourcedatatype.bones_string_vector_vector_vector[x].size() - 1)
//		 {
//			 file.open(string + "/" + std::to_string(y + 1), std::ios::binary);
//		 }
//	 }
// }
//
// // void FileWriter::unPackBones(SourceDataType& sourcedatatype, const std::string& string, const int& x)
// // {
// //	 std::ofstream file(string, std::ios::binary);
//
// //	 if (file.is_open())
// //	 {
// //		 for (int y = 0; y < sourcedatatype.bones_string_vector_vector_vector[x].size(); ++y)
// //		 {
// //			 M4x4 bone_m4x4{};
//
// //			 for (int z = 0; z < sourcedatatype.bones_string_vector_vector_vector[x][y].size(); ++z)
// //			 {
// //				 for (int w = 0; w < sourcedatatype.joints[x].size(); ++w)
// //				 {
// //					 if (sourcedatatype.bones_string_vector_vector_vector[x][y][z].find(sourcedatatype.joints[x][w]) != std::string::npos)
// //					 {
// //						 M4x4 bindpose_m4x4{};
// //						 // int bindpose_index = w * 16;
// //						 int bindpose_index = 0;
//
// //						 for (float& f : bindpose_m4x4.mat)
// //						 {
// //							 // f = sourcedatatype.bind_poses[x][bindpose_index++];
// //							 f = sourcedatatype.visual_bones_bonedata_vector_vector[x][w].visual_bones_transform_float_vector[bindpose_index++];
// //						 }
//
// //						 bone_m4x4 *= bindpose_m4x4;
//
// //						 file << w;
//
// //						 break;
// //					 }
// //				 }
//
// //				 // if (z < sourcedatatype.bones_string_vector_vector_vector[x][y].size() - 1)
// //				 // {
// //				 //	 unsigned char byte_unsigned_char = static_cast<unsigned char>(-1);
// //				 //	 file.write(reinterpret_cast<const char*>(&byte_unsigned_char), sizeof(unsigned char));
// //				 //	 // file << " ";
// //				 // }
// //				 // else
// //				 // {
// //				 //	 sourcedatatype.bones_m4x4_vector.push_back(bone_m4x4);
// //				 //	 bone_m4x4 = {};
// //				 // }
// //			 }
//
// //			 if (y < sourcedatatype.bones_string_vector_vector_vector[x].size() - 1)
// //			 {
// //				 unsigned char byte_unsigned_char = static_cast<unsigned char>(-1);
// //				 file.write(reinterpret_cast<const char*>(&byte_unsigned_char), sizeof(unsigned char));
// //				 // file << "\n";
// //			 }
// //		 }
//
// //		 file.close();
// //	 }
// //	 else
// //	 {
// //		 std::printf("FileWriter %s\n", string.c_str());
// //	 }
// // }
//
// // void FileWriter::unPackBonesM4x4(SourceDataType& sourcedatatype, const std::string& string, const int& x)
// // {
// //	 std::ofstream file(string);
//
// //	 if (file.is_open())
// //	 {
// //		 for (int x = 0; x < sourcedatatype.bones_m4x4_vector.size(); ++x)
// //		 {
// //			 for (int y = 0; y < 16; ++y)
// //			 {
// //				 file << sourcedatatype.bones_m4x4_vector[x].mat[y];
//
// //				 if (y < 15)
// //				 {
// //					 file << " ";
// //				 }
// //			 }
//
// //			 if (x < sourcedatatype.bones_m4x4_vector.size() - 1)
// //			 {
// //				 file << " ";
// //			 }
// //		 }
//
// //		 file.close();
// //	 }
// //	 else
// //	 {
// //		 std::printf("FileWriter %s\n", string.c_str());
// //	 }
// // }
